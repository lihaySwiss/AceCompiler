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
    int i =  0;
    Token *tok = new Token();

    //finish reading input on ;
    while(currWord[i] != '\n' && currWord != "")
    {
        tok->token = currWord;

        if (isalpha(currWord[i]))
        {
            tok->type = "IDENTIFIER";

            if(currWord == "while" || currWord == "for" || currWord == "if" || currWord == "else" || currWord == "return" )
            {       
                tok->type = "KEYWORD";
            }
            //here is where we would place a switch case to check for keywords before returning an identifier on the default case
            
            return (*tok);
        }

        else if (isdigit(currWord[i]))
        {
            int j = i;

            tok->type = "INT";
            tok->token = "";

            if(currWord.find(".") != std::string::npos)
            {
                tok->type = "DOUBLE";
            }

            while(isdigit(currWord[j]) || currWord[j] == '.')
            {
                tok->token += currWord[j++];
            }   

            return (*tok);
        }

        else if (currWord[i] == QUOTES || currWord[i] == DOUBLE_QUOTES)
        {
            tok->type = "STRING";
            tok->token = currWord.substr(1, currWord.length()-1);

            if (currWord[i] == QUOTES)
            {
                tok->type = "CHAR"; 
                tok->token = to_string(currWord[i+1]);
            }

            return(*tok);
        }

        // when the character is the end of the file
        else if(currWord [i] == EOF) 
        {
            tok->type = "EOF";
            return (*tok); 
        }
        
        else if (currWord[i] == '+' || currWord[i] == '-' || currWord[i] == '*' || currWord[i] == '/' || currWord[i] == '%')
        {
            tok->type = "BINOP";
            return(*tok);
        }

        else if(currWord[i] == '>' || currWord[i] == '<' || currWord[i] == '=' || currWord[i] == '&' || currWord[i] == '!')
        {
            tok->type = "LOGOP";
            return (*tok);  
        }

        i++;
    }       

    tok->type = "UNKNOWN";
    return (*tok);
}