#include "../headers/Lexer.hpp"
#include "../headers/DFA.hpp"
#include "../headers/Parser.hpp"

int main(int argc, char const * argv[]) {
    
    std::string path = "../tests/test.ace";
    
    Lexer *lexer = new Lexer(path);
    lexer->readFromFile();

    Parser *parser = new Parser();
    parser->setInputList(lexer->getTokenList());

    return 0;
}