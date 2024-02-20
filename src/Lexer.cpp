#include "../headers/Lexer.hpp"

Lexer::Lexer(std::string path)
{
    this->path = path;
    if (!this->dfa)
        this->dfa = new DFA();
}

void Lexer::readFromFile()
{
    int i = 0;
    std::string skip;
    std::string currWord = "";
    ifstream file;

    if (!file.is_open())
        file.open(this->path);

    if (!file.is_open())
    {
        std::cout << "error opening file :(" << std::endl;
        exit(1);
    }

    // Analyizing each word recived from the file
    // word is a sequence of charecters whice ends with a space
    while (file >> currWord)
    {
        analyze(currWord);
    }

    // Printing results for debugging
    for (Token token : this->tokenList)
    {
        std::cout << token.token << " ";
        std::cout << returnTokenString(token.type) << " ";
        std::cout << to_string(token.type) << std::endl;
    }
}

Token Lexer::analyze(std::string currWord)
{
    int i = 0, j = 0;
    std::string result = "";
    Token *t = new Token();

    int(*mat)[CHARS_NUM] = this->dfa->getMat();

    // Getting the token by stat from the matrix
    // if no matching state and finel state is posative identify as identifier
    // else identify as UNDEFINED
    while (mat[j][currWord[i]] != -1)
    {
        // the type will be the most recent valid state
        t->type = mat[j][currWord[i]];

        result += currWord[i];
        j = mat[j][currWord[i]];
        i++;
    }

    t->token = result;
    tokenList.push_back(*t);

    return (*t);
}

// Debugging that returns words for each code recived
std::string Lexer::returnTokenString(int code)
{
    switch (code)
    {
        case ID_INT:
            return "INT";
            break;

        case ID_CHAR:
            return "CHAR";
            break;

        case ID_IF_CONDITION:
            return "IF_CONDITION";
            break;

        case ID_ELSE_CONDITION:
            return "ELSE_CONDITION";
            break;

        case ID_WHILE_LOOP:
            return "WHILE_LOOP";
            break;

        case EQUAL:
            return "EQUAL";
            break;

        case BIGEER_EQUAL:
            return "BIGEER_EQUAL";
            break;

        case SMALLER_EQUAL:
            return "SMALLER_EQUAL";
            break;

        case BINOP_PLUS:
            return "BINOP_PLUS";
            break;

        case BINOP_DIV:
            return "BINOP_DIV";
            break;

        case BINOP_MINUS:
            return "BINOP_MINUS";
            break;

        case BINOP_MULT:
            return "BINOP_MULT";
            break;

        case BINOP_AND:
            return "BINOP_AND";
            break;

        case LOGIC_AND:
            return "LOGIC_AND";
            break;

        case LOGIC_OR:
            return "LOGIC_OR";
            break;

        case DEFINE_VAR:
            return "DEFINE_VAR";
            break;

        case LBRACE:
            return "LEFT_BRACKET";
            break;

        case RBRACE:
            return "RIGHT_BRACKET";
            break;

        case -1:
            return "NO SUCH TOKEN";
            break;

        default:
            return "IDENTIFIER";
            break;
    }
}