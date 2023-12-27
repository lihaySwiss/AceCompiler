#include "header/Lexer.h"
#define COMMENT_SIGN '#'

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

            std::cout <<  getToken(currWord.substr(i)).type << std::endl;
            i++;
        }
        i = 0;
        
    }
}


Token Lexer::getToken(std::string currWord)
{
    std::cout << currWord << std::endl;

    
    return t;
}