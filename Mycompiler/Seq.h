#ifndef SEQ_H
#define SEQ_H
#include "Stmt.h"

class Seq : public Stmt {
public:
    Stmt* stmt1;
    Stmt* stmt2;

    Seq(Stmt* s1, Stmt* s2) : stmt1(s1), stmt2(s2) {}

    void gen(int b, int a) override {
        if (stmt1 == Stmt::Null) {
            stmt2->gen(b, a);
        }
        else if (stmt2 == Stmt::Null) {
            stmt1->gen(b, a);
        }
        else {
            int label = newlabel();
            stmt1->gen(b, label);
            Node::setPendingLabel(label);  // ÑÓ³ÙÊä³ö label
            stmt2->gen(label, a);
        }
    }

};
#endif // SEQ_H
