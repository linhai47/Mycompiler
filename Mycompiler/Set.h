#ifndef SET_H
#define SET_H
#include "Stmt.h"
#include "Lexer.h" // 假设Lexer相关头文件
#include "symbols.h" // 假设Symbols相关头文件
#include "Id.h"
#include "Type.h"
class Set : public Stmt {
public:
    Expr* id;
    Expr* expr;

    Set(Expr* i, Expr* x) : id(i), expr(x) {
        
        if (check(id->type, expr->type) == nullptr) {
            error("Type error in assignment");
        }
    }

    Type* check(Type* p1, Type* p2){
        
       /* if (p1->isNumeric() && p2->isNumeric()) {
            cout << "is Numeric" << endl;
            return p2; 
        }
        else if (p1->isBool() && p2->isBool()) {
            cout << "is Bool" << endl;
            return p2; 
        }
        else if (p1->isChar() && p2->isChar()) {
            cout << "is Char" << endl;
            return p2;
        }
        else if (p1 == p2) {
            cout <<"is Null" <<endl;
            return p2;
        }*/

        if ( p1->numeric(p1) && p2->numeric(p2) ){
          
            if (p1 == nullptr) {
                cout << "p1 is nullptr" << endl;
            }
            return p1;
        }
    }

    void gen(int b, int a)
    {
       
        Expr* redExpr = expr->gen();
    /*    cout << "          " << b << "         " << a << endl;
        cout << "redExpr id        " << redExpr->toString() << "         " << id->toString() << endl;*/
        if (redExpr->toString() != "0" && id->toString() != "0") {
            // 输出赋值语句
    
            emit(id->toString() + " = " + redExpr->toString());
        }
    }
};
#endif // SET_H
