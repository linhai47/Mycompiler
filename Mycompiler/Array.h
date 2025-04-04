#ifndef ARRAY_H
#define ARRAY_H
#include "Type.h" // 假设已有Type类的定义，需包含其头文件
#include <string>

class Array : public Type {
public:
    Type* of;
    int size;
    Array(int sz, Type* p) : Type("[]", static_cast<int>(Tag::INDEX), sz* p->width), size(sz), of(p) {}
    string toString() const {
        return "[" + to_string(size) + "]" + of->toString();
    }
    bool isArray() const override { return true; }
};
#endif // ARRAY_H
