#include "Expr.h"
#include <iostream>





Expr* Expr::gen() {
    return this;
}

Expr* Expr::reduce() {
    return this;
}

void Expr::jumping(int t, int f) {
    emitjumps(toString(), t, f);
}

void Expr::emitjumps(const string& test, int t, int f) {
   /* std::cout << "Generating jump for " << toString() << " to L" << t << " or L" << f << std::endl;*/
    if (t != 0 && f != 0) {
        emit("if " + test + " goto L" + to_string(t));
        emit("goto L" + to_string(f));
    }
    else if (t != 0) {
        emit("if " + test + " goto L" + to_string(t));
    }
    else if (f != 0) {
        emit("iffalse " + test + " goto L" + to_string(f));
    }
   
}

std::string Expr::toString()const {
    return op->toString();
}

