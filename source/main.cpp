
#include "Lexer.cpp"
//#include "header/Lexer.h"

int main(int argc, char const * argv[]) {
    
    const char *FILE_PATH = "test.ace";
    ifstream file(FILE_PATH);
    
    Lexer *myLexer = new Lexer(&file);
    myLexer->readFromFile();

    file.close();
    return 0;
}