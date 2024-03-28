#include <vector>
#include <iostream> 
#include "Lexer.hpp"

enum non_terminal{
    PROGRAM = 900,
    DECLARATION,
    TYPE,
    VAR_DECLARATION,
    STATEMENT,
    EXPRESSION,
    RETURN_STATEMENT,
    TERM,
    FACTOR,
    LOGIC_EXPRESSION,
    LITERAL,
    LOOP,
    CONDITION,
    BINOP
};

class Production{
    public:
    non_terminal left;
    std::vector<int> right;
    
    Production(non_terminal left, std::vector<int> right){
        this->left = left;
        this->right = right;
    }
};