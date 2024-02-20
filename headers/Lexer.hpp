#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <list>
#include "Token.hpp"
#include "DFA.hpp"

#define COMMENT_SIGN '#'
#define QUOTES '\''
#define DOUBLE_QUOTES '\"'

using namespace std;

enum tokId {ID_IDENTIFIER = 1, 
            ID_NUMBER = 2,
            ID_INT = 26,
            ID_CHAR = 23,
            ID_BOOL = 31,
            ID_WHILE_LOOP = 14,
            ID_FOR_LOOP = 18,
            ID_IF_CONDITION = 3,
            ID_ELSE_CONDITION = 8,
            EQUAL = 58,
            BIGEER_EQUAL = 61,
            SMALLER_EQUAL = 64,
            BINOP_PLUS = 40,
            BINOP_DIV = 38,
            BINOP_MINUS = 42,
            BINOP_MULT = 44,
            BINOP_AND = 46,
            LOGIC_AND = 50,
            LOGIC_OR = 53,
            DEFINE_VAR = 67,
            LBRACE = 75,
            RBRACE = 77};
           

class Lexer
{

private:
    std::string _lastCollectedValue;
    list<Token> tokenList;
    std::string path;
    DFA *dfa;
    
public:
    
    Lexer(std::string path);

    void readFromFile();

    std::string returnTokenString(int code);

    Token analyze(std::string data);
};
