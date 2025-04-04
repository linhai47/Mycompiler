#ifndef REAL_H
#define REAL_H
#include <iostream>
#include "Token.h"
#include "Tag.h"

using namespace std;

class Real: public Token{
public:
    Real(float v):Token((Tag::REAL)),value(v){};
    string toString() const override{
        return to_string(value);
    }
private:
    const float value;
};

#endif // REAL_H
