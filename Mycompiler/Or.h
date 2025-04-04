#ifndef OR_H
#define OR_H
#include "Logical.h"

class Or : public Logical {
public:
    Or(Token* tok, Expr* x1, Expr* x2) :Logical(tok, x1, x2) {}
    void jumping(int t, int f) override {
        int label = (t!= 0)? t : newlabel();
        expr1->jumping(label, 0);
        expr2->jumping(t, f);
        if (t == 0) {
            emitlabel(label);
        }
    }
};
#endif // OR_H
