#ifndef NODE_H
#define NODE_H

#include "lexer.h"
#include <string>

class Node {
protected:
    int lexline;
    
public:
    static int labels;
     static int pending_label; 
    Node() :lexline(Lexer::line) {}
    void error(const string& s);
    static int newlabel();
    void emitlabel(int i);
    void emit(const string& s);
    virtual string toString()const;
    static void setPendingLabel(int label);
    static void emitlabelIfPending();
};

#endif
