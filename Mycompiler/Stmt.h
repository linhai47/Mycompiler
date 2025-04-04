#ifndef STMT_H
#define STMT_H
#include "Node.h" // 假设Node类的头文件

class Stmt : public Node {
public:
    Stmt() :after(0) {}
    static Stmt* Null;static Stmt* Enclosing;
    virtual void gen(int b, int a) {
       
    }
    int after;
    
    bool operator==(const Stmt& other) const {
        return this == &other;
    }
};


#endif // STMT_H
