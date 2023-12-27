#include <iostream>
#include <fstream>
#include "Token.h"


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
