#ifndef NOT_H
#define NOT_H
#include "Logical.h"

class Not : public Logical {
public:
    Not(Token* tok, Expr* x):Logical(tok, x, x) 
    {
       
        if (x->type != Type::Bool) {
            error("Type error: logical NOT requires boolean operand");
        }
    }
    void jumping(int t, int f) override{
        expr2->jumping(f, t);
    }
    std::string toString()const override {
        return op->toString() + " " + expr2->toString();
    }
};
#endif // NOT_H
