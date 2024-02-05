#include "../headers/DFA.hpp"
#define MAT_PATH "DFA/dfa"

static unsigned int nextFreeState = 0;

DFA::DFA()
{
    for (size_t i = 0; i < NUM_OF_STATES; i++)
        for (int j = 0; j < CHARS_NUM; j++)
            this->mat[i][j] = -1;

    makeDFA();
    writeToFile(MAT_PATH);
}

void DFA::addTokens(const std::string &token)
{
    int i;

    for (i = 0; i <= token.size(); i++)
    {
        if(this->mat[nextFreeState][token[i]] == -1)
        {
            this->mat[nextFreeState][token[i]] = nextFreeState;
            nextFreeState++;
        }
    }
    std::cout << token << ":" << nextFreeState << std::endl;
}

bool DFA::writeToFile(const std::string &path)
{
    std::ofstream file;

    file.open(path);

    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return false;
    }

    for (int i = 0; i < NUM_OF_STATES; i++)
    {
        for (int j = 0; j < CHARS_NUM; j++)
        {
            file << this->mat[i][j] << ",";
        }
        file << "\n";
    }
    return true;
}

bool DFA::readFromFile(const std::string &path)
{
    std::ifstream file;
    int i = 0, j = 0;

    if(!file.is_open())
        file.open(path);

    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return false;
    }

    while (file)
    {
        char ch = file.get();
        if (ch != '\n')
        {
            for (i = 0; i < NUM_OF_STATES; i++)
            {
                for (j = 0; j < CHARS_NUM; j++)
                {
                    this->mat[i][j] = ch;
                }
            }
        }
    }

    return true;
}

void DFA::makeDFA()
{
    // Types
    addTokens("char");
    addTokens("int");
    addTokens("bool");
    addTokens("void");

    // Conditions
    addTokens("if");
    addTokens("else");

    // Loops
    addTokens("while");
    addTokens("for");

    // Binop
    addTokens("/");
    addTokens("+");
    addTokens("-");
    addTokens("*");
    addTokens("&");
    addTokens("%");

    // Logical gates
    addTokens("&&");
    addTokens("||");
    addTokens("~");
    addTokens("==");

    // Special
    addTokens(":=");
    addTokens(";");
    addTokens("\'");
    addTokens("\"");
}
