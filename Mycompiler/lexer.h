#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <stdexcept>
#include <string.h>

#include "symbols.h"
#include "Word.h"
#include "Num.h"
#include "Real.h"
#include <unordered_map>

using namespace std;

class Lexer {
public:
    static int line;
    char peek=' ';
    unordered_map<std::string, Word*> words; 

    void reserve(Word* w);
    void readch();
    bool readch(char c);
    Token* scan();
    Lexer();
};




#endif // LEXER_H
