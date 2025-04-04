#ifndef TYPE_H
#define TYPE_H
#include "Word.h" // 假设已有Word类的定义，需包含其头文件
#include <string>

class Type : public Word {
public:
    int width;
    Type(const std::string& s, int tag, int w) : Word(s, tag), width(w) {}
    //bool operator==(const Type& other) const;
    //Type operator=(const Type& other) const;
    //bool operator!=(const Type& other) const {
    //    // 比较逻辑
    //    return false;
    //}
    static bool numeric(Type* p);

    
    static Type* max(Type* p1, Type* p2);


    virtual bool isArray() const { return false; }

  
    virtual bool isNumeric() const;

 
    virtual bool isBool() const;


    virtual bool isChar() const;
    static Type* Int;
    static Type* Float;
    static Type* Char;
    static Type* Bool;
    // 设置一个空量
    static Type* NULLPTR;
};


#endif // TYPE_H
