#ifndef UNARY_H
#define UNARY_H
#include "Op.h"
#include "Lexer.h" // 假设Lexer相关头文件
#include "Symbols.h" // 假设Symbols相关头文件

class Unary : public Op {
public:
    Expr* expr;
    Unary(Token* tok, Expr* x): Op(tok,nullptr), expr(x) {
        type = Type::max(Type::Int, expr->type);
        if (type == nullptr) {
            error("type error");
        }
    }
    Expr* gen() {
        return new Unary(op, expr->reduce());
    }
    std::string toString()  {
        ostringstream oss;
        oss << op->toString() << " " << expr->toString(); 
        return oss.str();
    }
};
#endif // UNARY_H
