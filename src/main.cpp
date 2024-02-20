#include "../headers/Lexer.hpp"
#include "../headers/DFA.hpp"

int main(int argc, char const * argv[]) {
    
    std::string path = "../tests/test.ace";
    
    Lexer *lexer = new Lexer(path);
    lexer->readFromFile();

    return 0;
}