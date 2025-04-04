#ifndef SETELEM_H
#define SETELEM_H
#include "Stmt.h"
#include "Lexer.h" // 假设Lexer相关头文件
#include "Symbols.h" // 假设Symbols相关头文件
#include "Access.h"

class SetElem : public Stmt {
public:
    Id* array;
    Expr* index;
    Expr* expr;

    SetElem(Access* x, Expr* y) : array(x->array), index(x->index), expr(y) {
        
        if (check(x->type, expr->type) == nullptr) {
            error("Type error in array element assignment");
        }
    }

    Type* SetElem::check(Type* p1, Type* p2)
    {  
        if (p1->isArray() || p2->isArray()) {
            return nullptr;
        }
        else if (p1 == p2) {
            return p2;
        }
        else if (p1->isNumeric() && p2->isNumeric()) {
            return p2;
        }
        return nullptr;
    }

    void gen(int b, int a) {
  
        std::string s1 = index->reduce()->toString();
        std::string s2 = expr->reduce()->toString();
        ostringstream oss;
        oss << array->toString() << " [ " << s1 << " ] = " << s2;
        emit(oss.str());
    }
};
#endif // SETELEM_H
