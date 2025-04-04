#include "Env.h"


void Env::put(Token* w, Id* i) {
    table[w] = i;
}

Id* Env::get(Token* w) {
    for (Env* e = this; e != nullptr; e = e->prev) {
        auto it = e->table.find(w);
        if (it != e->table.end()) {
            return it->second;
        }
    }
    return nullptr;
}