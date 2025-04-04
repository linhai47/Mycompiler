#ifndef IF_H
#define IF_H
#include "Stmt.h"
#include "Expr.h"
#include "Symbols.h" // 假设Symbols相关头文件

class If : public Stmt {
public:
    Expr* expr;
    Stmt* stmt;
    If(Expr* x, Stmt* s) : expr(x), stmt(s) {
        if (expr->type != Type::Bool) {
            expr->error("boolean required in if");
        }
    }

    void gen(int b, int a) override {
        int label = newlabel();
        //cout<<"IF :" << a << " " << b << endl;
        // 延迟输出 label（等到 emit 的时候输出）
        Node::setPendingLabel(b);

        expr->jumping(0, a);  // 如果 expr 为 false，跳转到 a
        stmt->gen(label, a);  // 然后执行 stmt
    }
};
#endif // IF_H
