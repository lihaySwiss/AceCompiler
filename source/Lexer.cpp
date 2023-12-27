#include "header/Lexer.h"

Lexer::Lexer(ifstream *file) {
    this->file = file;
}

void Lexer::readFromFile()
{
    int i  = 0;
    std::string currWord = " " ;

    while((*file) >> currWord)
    {
         // skip whitespace and comments
        while(currWord[i] != '#' && !isspace(currWord[i]) && currWord[i] != ';') 
        {
            std::cout <<  getToken(currWord.substr(i)).type << std::endl;
            i++;
        }
        i = 0;
        
    }
}


Token Lexer::getToken(std::string currWord)
{
 
}