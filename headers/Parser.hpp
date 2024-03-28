#pragma once
#include "Token.hpp"
#include "Lexer.hpp"
#include "Stack.hpp"
#include "Production.hpp"
#include <vector>
#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>


//example: rules for type 
// left-> Token(NON-TERMINAL) right -> (Token(ID_INT))
// left-> Token(NON-TERMINAL) right -> (Token(ID_CHAR))
// left-> Token(NON-TERMINAL) right -> (Token(ID_BOOL))
struct Rule{
    non_terminal left;
    list<int> right;
};

struct ParseTree{
    Rule rule;
    std::vector<ParseTree> children;
};



class Parser{
private:
    Stack<int> tokenStack;
    std::list<Token> inputList;
    list<Production> productions;


public:
    Parser();
    void setInputList(list<Token> inputList){this->inputList = inputList;}
    bool readFile();

};