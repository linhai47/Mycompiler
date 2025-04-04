#ifndef WORD_H
#define WORD_H
#include <iostream>
#include "Token.h"
#include "Tag.h"

using namespace std;
class Word : public Token {
public:
   
    Word(const string& s, int tag) : Token(tag), lexeme(s) {}
   
    string toString() const { return lexeme; }
    bool operator==(const Word& other) const {
        return (lexeme == other.lexeme&&tag==other.tag);
    }
    static  Word Qand, Qor, eq, ne, le, ge, minus, True, False, temp;


    string lexeme;
};
namespace std {
    template <>
    struct hash<Word> {
        std::size_t operator()(const Word& t) const {
            std::size_t h1 = std::hash<std::string>()(t.toString());
            std::size_t h2 = std::hash<int>()(t.tag); 
            
            return h1 ^ (h2 << 1);
        }
    };
}

#endif // WORD_H
