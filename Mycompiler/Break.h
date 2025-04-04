#ifndef BREAK_H
#define BREAK_H

#include "Stmt.h"

class Break : public Stmt {
public:
    Stmt* enclosingStmt;

    Break() {
        if (Stmt::Enclosing == Stmt::Null) {
            error("break statement not within a loop or switch");
        }
        enclosingStmt = Stmt::Enclosing;
    }

    void gen(int b, int a) override {
       /* cout << a << "  " << b << endl;*/
        Node::setPendingLabel(b); // 确保当前 block 的标签输出
        emit("goto L" + std::to_string(2));
    }
};

#endif // BREAK_H
