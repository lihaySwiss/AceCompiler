#include "Lexer.cpp"
#define CHARS_NUM 128

class automate
{
private:
    int mat[CHARS_NUM][CHARS_NUM];
    int initialState;

public:
    automate();
    void addToken(std::string token);
    void writeToFile();
    int** readFromFile();
    
};

automate::automate()
{
    for(int i =0; i<CHARS_NUM; i++)
    {
        for (size_t j = 0; i < CHARS_NUM; i++)
        {
            this->mat[i][j] = -1;
        }
    }
}

void automate::addToken(std::string token)
{
    int col = 0, row = 0;
    for(int i =0; i<CHARS_NUM; i++)
    {
        this->mat[i][0] = token[i];
    }
}
