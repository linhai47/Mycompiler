#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include "Lexer.h"
#include "Symbols.h"
#include "inter.h"
#include "Env.h"

class Parser {
private:
    Lexer &lex;
    Token* look;
    Env* top = nullptr;
    int used = 0;

public:
    Parser(Lexer& l) : lex(l) { move(); }


    void Parser::move() {
        look = lex.scan();
        
    }

    [[noreturn]] void error(const std::string& s) {
        /*throw runtime_error("near line " + to_string(lex.line) + ": " + s);*/
    }

    void match(int t) {
       
        if (look->tag == t) {
            move();
        }
        else {
            error("syntax error: expected '" + to_string(t) + "'");
        }
    }

    void program();
    Stmt* block();
    void decls();
    Type* type();
    Type* dims(Type* p);
    Stmt* stmts();
    Stmt* stmt();
    Stmt* assign();
    Expr* Bool();
    Expr* join();
    Expr* equality();
    Expr* rel();
    Expr* expr();
    Expr* term();
    Expr* unary();
    Expr* factor();
    Access* offset(Id* a);
};

#endif // PARSER_H
