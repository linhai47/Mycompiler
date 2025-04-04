#ifndef ELSE_H
#define ELSE_H
#include "Stmt.h"
#include "Expr.h"
#include "Symbols.h" // 假设Symbols相关头文件

class Else : public Stmt {
public:
    Expr* expr;
    Stmt* stmt1;
    Stmt* stmt2;

    Else(Expr* x, Stmt* s1, Stmt* s2) : expr(x), stmt1(s1), stmt2(s2) {
        if (expr->type!= Type::Bool) {
            expr->error("boolean required in if");
        }
    }

    void gen(int b, int a) override {
        int label1 = newlabel();  // then 分支的 label
        int label2 = newlabel();  // else 分支的 label
        
        int endLabel = (a != 0) ? a : newlabel(); // if 之后的位置

        expr->jumping(0, label2);           // 若表达式为假，跳转到 else

        Node::setPendingLabel(label1);      // THEN 分支：延迟输出 label
        stmt1->gen(label1, endLabel);       // 生成 THEN 分支代码
        emit("goto L" + std::to_string(endLabel)); // THEN 执行完跳转到 END

        Node::setPendingLabel(label2);      // ELSE 分支：延迟输出 label
        stmt2->gen(label2, endLabel);       // 生成 ELSE 分支代码

        if (a == 0) {
            
            emitlabel(endLabel);            // 输出结束 label
        }
    }

};
#endif // ELSE_H
