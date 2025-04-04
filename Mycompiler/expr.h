#ifndef EXPR_H
#define EXPR_H

#include "node.h"
#include "token.h" // 假设已有Token类定义，需包含对应头文件
#include "type.h"  // 假设已有Type类定义，需包含对应头文件
#include <string>

class Expr : public Node {
public:
    Token *op;
    Type *type;
    Expr(Token* tok, Type* p) : op(tok), type(p) {}
    
    virtual Expr* gen();
    virtual Expr* reduce();
    virtual void jumping(int t, int f);
    void emitjumps(const std::string& test, int t, int f);
    string toString() const override;
};

#endif
