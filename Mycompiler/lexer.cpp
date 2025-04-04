#include "lexer.h"
#include "Tag.h"
#include "Word.h"
#include "Type.h"
#include <iostream>
#include <sstream>
Word Word::Qand("&&", Tag::AND);
Word Word::Qor("||", Tag::OR);
Word Word::eq("==", Tag::EQ);
Word Word::ne("!=", Tag::NE);
Word Word::le("<=", Tag::LE);
Word Word::ge(">=", Tag::GE);
Word Word::minus("minus", Tag::MINUS);
Word Word::True("true", Tag::TRUE);
Word Word::False("false", Tag::FALSE);
Word Word::temp("t", Tag::TEMP);
// 静态常量的定义
Lexer::Lexer(){
    // 将关键字和保留字放入单词表
    reserve(new Word("if", Tag::IF));
    reserve(new Word("else", Tag::ELSE));
    reserve(new Word("while", Tag::WHILE));
    reserve(new Word("do", Tag::DO));
    reserve(new Word("break", Tag::BREAK));
    reserve(&Word::True);
    reserve(&Word::False);
    reserve(Type::Int);
    reserve(Type::Char);
    reserve(Type::Bool);
    reserve(Type::Float);
}

int Lexer::line = 1;

void Lexer::reserve(Word* w) {
    words[w->lexeme] = w;
}

void Lexer::readch()
{
    peek = cin.get();
    //cout << "read ch: " << peek << endl;
}

bool Lexer::readch(char c)
{
    readch(); 
   
    if (peek != static_cast<int>(c)) { 
        return false;
    }
    peek = ' '; 
    return true;
}

Token* Lexer::scan() {
    for (;; readch()) {
        if (peek == ' ' || peek == '\t') continue;
        else if (peek == '\n') line++;
        else break;
    }

    switch (peek) {
    case '&':
        if (readch('&')) return &Word::Qand;
        else return new Token('&');
    case '|':
        if (readch('|')) return &Word::Qor;
        else return new Token('|');
    case '=':
        if (readch('=')) return &Word::eq;
        else return new Token('=');
    case '!':
        if (readch('=')) return &Word::ne;
        else return new Token('!');
    case '<':
        if (readch('=')) return &Word::le;
        else return new Token('<');
    case '>':
        if (readch('=')) return &Word::ge;
        else return new Token('>');
    }

    if (isdigit(peek)) {
        int v = 0;
        do {
            v = 10 * v + (peek - '0');
            readch();
        } while (isdigit(peek));

        if (peek != '.') return new Num(v);

        float x = v;
        float d = 10.0f;
        for (;;) {
            readch();
            if (!isdigit(peek)) break;
            x += (peek - '0') / d;
            d *= 10.0f;
        }
        return new Real(x);
    }

    if (isalpha(peek)) {
        std::stringstream ss;
        do {
            ss << static_cast<char>(peek);
            readch();
        } while (isalnum(peek));

        std::string s = ss.str();
        auto it = words.find(s);
        if (it != words.end()) return it->second;

        Word* w = new Word(s, Tag::ID);
        words[s] = w;
        return w;
    }

    if (peek == EOF) {
        return new Token(Tag::QEOF);
    }
    else {
        Token* tok = new Token(peek);
        peek = ' ';
        return tok;
    }
}