#ifndef ID_H
#define ID_H
#include "Expr.h"
#include "Word.h" // 假设已有Word类定义，需包含对应头文件
#include "Type.h"  // 假设已有Type类定义，需包含对应头文件

class Id : public Expr {
public:
    int offset;
    Id(Word* id, Type* p, int b) :Expr(id, p), offset(b) {}
    

};
#endif // ID_H
