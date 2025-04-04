#ifndef CONSTANT_H
#define CONSTANT_H
#include "Expr.h"
#include "Lexer.h" // 假设Lexer相关头文件
#include "Symbols.h" // 假设Symbols相关头文件

class Constant : public Expr {
public:
    Constant(Token* tok, Type* p) :Expr(tok, p) {}
    Constant(int i) :Expr(new Num(i), Type::Int) {}

    static  Constant* True;
    static  Constant* False;

    void jumping(int t, int f)override
    {
        if (this == True && t != 0) {
            emit("goto L" + std::to_string(t));  
        }
        else if (this == False && f != 0) {
            emit("goto L" + std::to_string(f));   
        }
    }
};



#endif // CONSTANT_H
