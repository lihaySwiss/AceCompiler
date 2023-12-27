#include "Lexer.cpp"
#define CHARS_NUM 128

class automate
{
private:
    int** mat[CHARS_NUM][CHARS_NUM];

public:
    void writeToFile();
    int** readFromFile();
    
};