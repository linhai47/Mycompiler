#ifndef ENV_H
#define ENV_H

#include "Id.h"
#include "Token.h"
#include <unordered_map>

class Env {
public:
    std::unordered_map<Token*, Id*> table;
    Env* prev;

    Env(Env* n = nullptr) :prev(n) {}
    void put(Token* w, Id* i);
    Id* get(Token* w);
};

#endif // ENV_H
