#ifndef REL_H
#define REL_H
#include "Logical.h"
#include "Lexer.h" // 假设Lexer相关头文件
#include "Symbols.h" // 假设Symbols相关头文件
#include <string>

class Rel : public Logical {
public:
    Rel(Token* tok, Expr* x1, Expr* x2) :Logical(tok, x1, x2) {}

    Type* check(Type* p1, Type* p2) override{
        if (p1->isArray() || p2->isArray()) {
            return nullptr;
        }
        else if (p1 == p2) {
            return Type::Bool;
        }
        return nullptr;
    }

    void jumping(int t, int f) override{
        Expr* a = expr1->reduce();
        Expr* b = expr2->reduce();
        std::string test = a->toString() + " " + op->toString() + " " + b->toString();
        emitjumps(test, t, f);
    }
};
#endif // REL_H
