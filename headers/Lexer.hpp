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
            ID_INT = 27,
            ID_CHAR = 24,
            ID_BOOL = 32,
            ID_VOID = 37,
            ID_WHILE_LOOP = 15,
            ID_FOR_LOOP = 19,
            ID_IF_CONDITION = 4,
            ID_ELSE_CONDITION = 9,
            EQUAL = 59,
            BIGEER_EQUAL = 62,
            SMALLER_EQUAL = 65,
            BINOP_PLUS = 41,
            BINOP_DIV = 39,
            BINOP_MINUS = 43,
            BINOP_MULT = 45,
            BINOP_AND = 47,
            LOGIC_AND = 51,
            LOGIC_OR = 54,
            DEFINE_VAR = 68,
            SEMI_COLON = 69,
            APOSTROPHE = 72,
            LPARAN = 76,
            RPARAN = 78,
            RBRACE = 80,
            LBRACE = 82,
            ID_RETURN = 89,
            ID_TRUE = 94,
            ID_FALSE = 99};
           

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

    Token analyze(std::string currWord);

    list<Token> getTokenList() { return this->tokenList; }
};
