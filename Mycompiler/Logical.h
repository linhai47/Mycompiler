#ifndef LOGICAL_H
#define LOGICAL_H
#include "expr.h"
#include "lexer.h" // 假设Lexer相关头文件
#include "symbols.h" // 假设Symbols相关头文件
#include "Temp.h"
#include <string>

class Logical : public Expr {

public:
    Expr* expr1;
    Expr* expr2;
    Logical(Token* tok, Expr* x1, Expr* x2) : Expr(tok, nullptr), 
        expr1(x1),
        expr2(x2)
    {
        type = check(expr1->type, expr2->type); 
        if (type == nullptr) {
            error("Type error in logical expression"); 
        }
    }
    virtual Type* check(Type* p1, Type* p2)
    {
        
        if (p1 == Type::Bool && p2 == Type::Bool) {
            return Type::Bool;
        }
        return nullptr;
    }
    Expr* gen() override {
       /* cout << "Logical gen" << endl;*/
        int f = newlabel();
        int a = newlabel();
        Temp* temp = new Temp(type);
        this->jumping(0, f);
        emit(temp->toString() + " = true");
        emit("goto L" + std::to_string(a));
        emitlabel(f);
        emit(temp->toString() + " = false");
        emitlabel(a);
        return temp;
    }
    std::string toString()const override {
        return expr1->toString() + " " + op->toString() + " " + expr2->toString();
    }
};
#endif // LOGICAL_H
