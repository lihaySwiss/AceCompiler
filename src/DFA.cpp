#include "../headers/DFA.hpp"
#include <ctype.h>
#include <string>
#define MAT_PATH "./DFA/dfa"

static int freeState = 1;

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
    int i = 0;
    int currState = 0;

    // Give all letters state of 1 that is identifier
    if (freeState < 2)
    {
        int alpha = 'a';

        while (isalpha(alpha))
        {
            for(int j = 0; j < NUM_OF_STATES; j++)
            {
                mat[j][alpha] = freeState;
            }
            alpha++;
        }
        freeState++;
    }

    // Checking if the recived token is new 
    // or a prefix of older token 
    while (this->mat[currState][token[i]] != -1 && this->mat[currState][token[i]] != 1)
    {
        currState = mat[currState][token[i]];
        i++;
    }

    // Making sure each state will point to the next
    // state in the matrix(state machine)
    for (; i < token.size(); i++)
    {
        mat[currState][token[i]] = freeState;
        currState = freeState++;
    }
    freeState++;
}

bool DFA::writeToFile(const std::string &path)
{
    std::ofstream file;

    file.open(path);

    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
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

    if (!file.is_open())
        file.open(path);

    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
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

    // Conditions
    addTokens("if");
    addTokens("else");

    // Loops
    addTokens("while");
    addTokens("for");

    // Variables
    addTokens("char");
    addTokens("int");
    addTokens("bool");
    addTokens("void");

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
    addTokens("<=");
    addTokens(">=");
    

    // Special
    addTokens(":=");
    addTokens(";");
    addTokens("\'");
    addTokens("\"");
    addTokens("(");
    addTokens(")");
}
