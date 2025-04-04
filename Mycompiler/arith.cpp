#include "Arith.h"
#include <sstream>



Arith::Arith(Token* tok, Expr* x1, Expr* x2)
    : Op(tok, nullptr), 
    expr1(x1),
    expr2(x2)
{
    type = Type::max(expr1->type, expr2->type);
    if (type == nullptr) {
        error("Type error in arithmetic expression"); 
    }
}

Expr* Arith::gen() {
    return new Arith(op, expr1->reduce(), expr2->reduce());
}

string Arith::toString() const {
    std::ostringstream oss;
    oss << expr1->toString() << " " << op->toString() << " " << expr2->toString();
    return oss.str();
}
