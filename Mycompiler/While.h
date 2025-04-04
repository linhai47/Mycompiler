#ifndef WHILE_H
#define WHILE_H
#include "Stmt.h"
#include "Expr.h"
#include "Symbols.h" // 假设Symbols相关头文件

class While : public Stmt {
public:
    Expr* expr;
    Stmt* stmt;

    While(Expr* x, Stmt* s) : expr(x), stmt(s) {
        
        if (expr->type != Type::Bool) {
            expr->error("boolean required in while loop");
        }
    }

       
    void gen(int b, int a) {
    after = a;
    int loopLabel = newlabel();
    
    Node::setPendingLabel(b);       // 延迟输出 b 的 label
    expr->jumping(0, after);

    Node::setPendingLabel(loopLabel);  // 延迟输出 loopLabel
    stmt->gen(loopLabel, b);           // emit 的时候会自动输出 label

    Node::emit("goto L" + std::to_string(b));

    if (a != 0) {
       
        after = newlabel();
        Node::setPendingLabel(after);  // 延迟输出 after
        // 等下一句 emit 时输出这个 label
    }
}
};
#endif // WHILE_H
