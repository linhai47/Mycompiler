#ifndef ACCESS_H
#define ACCESS_H
#include "Op.h"
#include "Lexer.h" // 假设Lexer相关头文件
#include "Symbols.h" // 假设Symbols相关头文件
#include "Word.h"
#include "Id.h"
#include <string>

class Access : public Op {
public:
    Id* array;
    Expr* index;
    Access(Id* a, Expr* i, Type* p) :
        Op(new Word("[]", Tag::INDEX), p),
        array(a), index(i) {
    }
    Expr* gen() override {
        return new Access(array, index->reduce(), type);
    }
    void jumping(int t, int f) override {
        emitjumps(reduce()->toString(), t, f);
    }
    std::string toString() const override {
        return array->toString() + " [ " + index->toString() + " ]";
    }
};
#endif // ACCESS_H
