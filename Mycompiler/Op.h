#ifndef OP_H
#define OP_H


#include "Expr.h"
#include "Token.h" // 假设已有Token类定义，需包含对应头文件
#include "Type.h"  // 假设已有Type类定义，需包含对应头文件
#include "Temp.h"
#include <sstream>
#include <string>
#include <iostream>

static int tempCount = 0;
class Op : public Expr {
public:
    Op(Token* tok, Type* p) :Expr(tok, p) {}

    virtual Expr* reduce() override {
        Expr* x = gen();         
        Temp* t = new Temp(type); 

       
        ostringstream oss;
        oss << t->toString() << " = " << x->toString();
        emit(oss.str());

        return t; 
    }
};


#endif // OP_H
