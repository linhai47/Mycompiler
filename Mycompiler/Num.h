#ifndef NUM_H
#define NUM_H
#include "Token.h"
#include "Tag.h"

class Num: public Token{
public:
    Num (int v):Token((Tag::NUM)),value(v){};
    string toString() const override{
        return to_string(value);

    }

    const int value;
};

#endif // NUM_H
