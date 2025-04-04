#ifndef TEMP_H
#define TEMP_H
#include "expr.h"
#include "symbols.h"
#include "lexer.h"

class Temp : public Expr {
public:
    static int count;
    int number;

    Temp(Type* p) :Expr(&Word::temp, p), number(++count) {}
    string toString() const override{
        return "t" +to_string(number);
    }
};



#endif // TEMP_H
