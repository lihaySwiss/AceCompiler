#include <iostream>
#include <fstream>

#define CHARS_NUM 128
#define NUM_OF_STATES 60

static unsigned int nextFreeState = 0;

class DFA
{
private:
    int mat[NUM_OF_STATES][CHARS_NUM];

public:
    // DFA handle
    DFA();
    void makeDFA();
    void addTokens(const std::string &token);

    // file handle
    bool writeToFile(const std::string &path);
    bool readFromFile(const std::string &path);

    int (*getMat())[CHARS_NUM] { return this->mat; }
};

DFA::DFA()
{
    for (size_t i = 0; i < NUM_OF_STATES; i++)
        for (int j = 0; j < CHARS_NUM; j++)
        {
            {
                this->mat[i][j] = -1;
            }
        }
    makeDFA();
}

void DFA::addTokens(const std::string &token)
{
    int i;

    for (i = 0; i <= token.size()-1; i++)
    {
        if(this->mat[nextFreeState][token[i]] == -1)
        {
            this->mat[nextFreeState][token[i]] = nextFreeState++;
        }
    }
    nextFreeState++;
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
