
#include "Lexer.cpp"
#include "DFA.cpp"

int main(int argc, char const * argv[]) {
    
    std::string PATH_OF_DFA = "DFA/dfaFile.txt";

    DFA *dfa = new DFA();

    dfa->writeToFile(PATH_OF_DFA);

    return 0;
}