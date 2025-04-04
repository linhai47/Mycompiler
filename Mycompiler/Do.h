#ifndef DO_H
#define DO_H
#include "Stmt.h"
#include "Expr.h"
#include "Symbols.h" // 假设Symbols相关头文件

class Do : public Stmt {
public:
    Expr* expr;
    Stmt* stmt;

    Do(Stmt* s, Expr* x) : stmt(s), expr(x) {
       
        if (expr->type != Type::Bool) {
            expr->error("boolean required in do-while loop");
        }
    }

   /* void init(Stmt* s, Expr* x) {
        stmt = s;
        expr = x;
        if (expr->type!= Type::Bool) {
            expr->error("boolean required in do");
        }
    }*/

    void gen(int b, int a) override {
        after = a;
        int label = newlabel();
     /*   cout <<"Do    " << a << " " << b << endl;*/
        stmt->gen(b, label);             // 先生成循环体语句
        Node::setPendingLabel(label);    // 延迟输出 label
        expr->jumping(b, 0);             // 如果条件为真跳回开头，否则退出
    }
};
#endif // DO_H
