#include "../headers/Parser.hpp"

Parser::Parser()
{
    //definig program
    productions.push_back(Production(PROGRAM, {DECLARATION, PROGRAM}));
    productions.push_back(Production(PROGRAM, {DECLARATION}));
    
    //defining declarations
    productions.push_back(Production(VAR_DECLARATION, {TYPE, ID_IDENTIFIER, VAR_DECLARATION, LITERAL}));
    
    //defining types
    productions.push_back(Production(TYPE, {ID_INT}));
    productions.push_back(Production(TYPE, {ID_CHAR}));
    productions.push_back(Production(TYPE, {ID_BOOL}));
    productions.push_back(Production(TYPE, {ID_VOID}));

    //defining literals
    productions.push_back(Production(LITERAL, {ID_NUMBER}));
    productions.push_back(Production(LITERAL, {APOSTROPHE,ID_IDENTIFIER,APOSTROPHE}));
    productions.push_back(Production(LITERAL, {ID_TRUE}));
    productions.push_back(Production(LITERAL, {ID_FALSE}));
    
    //definig loops
    productions.push_back(Production(LOOP, {ID_WHILE_LOOP, LPARAN, LOGIC_EXPRESSION, RPARAN, LBRACE, PROGRAM, RBRACE}));
    productions.push_back(Production(LOOP, {ID_FOR_LOOP, LPARAN, VAR_DECLARATION, SEMI_COLON, LOGIC_EXPRESSION, SEMI_COLON, BINOP, RPARAN, LBRACE, PROGRAM, RBRACE}));
    
    //defining binops
    productions.push_back(Production(BINOP, {ID_IDENTIFIER, BINOP_MINUS, EXPRESSION}));
    productions.push_back(Production(BINOP, {ID_IDENTIFIER, BINOP_PLUS, EXPRESSION}));
    productions.push_back(Production(BINOP, {ID_IDENTIFIER, BINOP_MULT, EXPRESSION}));
    productions.push_back(Production(BINOP, {ID_IDENTIFIER, BINOP_DIV, EXPRESSION}));
    productions.push_back(Production(BINOP, {ID_IDENTIFIER, BINOP_PLUS, BINOP_PLUS}));
    productions.push_back(Production(BINOP, {ID_IDENTIFIER, BINOP_MINUS, BINOP_MINUS}));

    //defining conditions
    productions.push_back(Production(CONDITION, {ID_IF_CONDITION, LPARAN, LOGIC_EXPRESSION, RPARAN, LBRACE, PROGRAM, RBRACE}));
    productions.push_back(Production(CONDITION, {ID_IF_CONDITION, LPARAN, LOGIC_EXPRESSION, RPARAN, LBRACE, PROGRAM, RBRACE, ID_ELSE_CONDITION, LBRACE, PROGRAM, RBRACE}));
    

    //defining expressions
    productions.push_back(Production(EXPRESSION, {ID_IDENTIFIER, BINOP, EXPRESSION}));
    productions.push_back(Production(EXPRESSION, {ID_IDENTIFIER}));

}

bool Parser::readFile()
{
    string line;                    /* string to hold each line */
    vector<vector<std::string>> array;     /* vector of vector<int> for 2d array */
    ifstream f("ParserGen/parser_generator.csv"); /* open file */

    while (getline (f, line)) {         /* read each line */
        string val;                     /* string to hold value */
        vector<string> row;                /* vector for row of values */
        stringstream s (line);          /* stringstream to parse csv */
        while (getline (s, val, ','))   /* for each value */
            row.push_back (val);  /* convert to int, add to row */
        array.push_back (row);          /* add row to array */
    }
    f.close();

    cout << "complete array\n\n";
    for (auto& row : array) {           /* iterate over rows */
        for (auto& val : row)           /* iterate over vals */
            cout << val << "  ";        /* output value      */
        cout << "\n";                   /* tidy up with '\n' */
    }
    return 0;

}
