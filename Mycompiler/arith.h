#ifndef ARITH_H
#define ARITH_H

#include "Op.h"
#include "lexer.h"
#include "symbols.h"
class Arith : public Op  {
public:
    Expr* expr1;
    Expr* expr2;
    Arith(Token* tok, Expr* x1, Expr* x2);
    Expr* gen() override;
    std::string toString() const override;
};

#endif
