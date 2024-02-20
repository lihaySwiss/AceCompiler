#include <iostream>
#include <fstream>
#include "Token.cpp"

#define COMMENT_SIGN '#'
#define QUOTES '\''
#define DOUBLE_QUOTES '\"'

using namespace std;

class Lexer
{

private:
    std::string _lastCollectedValue;
    ifstream *file;
    
public:
    
    Lexer(ifstream *file);

    void readFromFile();
    Token getToken(std::string currWord);
};


Lexer::Lexer(ifstream *file) {
    this->file = file;
}

void Lexer::readFromFile()
{
    int i  = 0;
    std::string skip;
    std::string currWord = "" ;

    while((*file) >> currWord)
    {
        // skip whitespace
        while(!isspace(currWord[i]) && currWord[i] != ';') 
        {
            //getline((*file), skip, COMMENT_SIGN); //skip comments

            std::cout <<  getToken(currWord).type << std::endl;
            i++;
        }
        i = 0;
        
    }
}


Token Lexer::getToken(std::string currWord)
{
    std::cout << currWord << std::endl;
    Token* t = new Token();
    
    t->type = "ID";
    return (*t);
}