#include "Type.h"

// 定义静态常量成员变量（避免在多个源文件重复定义）
Type* Type::Int = new Type("int", Tag::BASIC, 4);
Type* Type::Float = new Type("float", Tag::BASIC, 8);
Type* Type::Char = new Type("char", Tag::BASIC, 1);
Type* Type::Bool = new Type("bool", Tag::BASIC, 1);
//Type* Type::NULLPTR =new Type("nullptr", Tag::BASIC, 1);
// 构造函数定义


// 重载 == 运算符
//bool Type::operator==(const Type& other) const {
//    return (this->width == other.width) && (this->toString() == other.toString());
//}
//
//Type Type::operator=(const Type &other) const
//{
//    return other;
//}
//
//// 判断是否为数值类型
//bool Type::numeric(Type* p) {
//    return (p == Type::Char || p == Type::Int || p == Type::Float);
//}

// 计算两个 Type 的最大类型
bool Type::numeric(Type* p)
{
    return (p == Type::Char || p == Type::Int || p == Type::Float);
}

Type* Type::max(Type* p1, Type* p2)
{
    if (!numeric(p1) || !numeric(p2)) return nullptr; 

    if (p1 == Type::Float || p2 == Type::Float) return Type::Float;
    else if (p1 == Type::Int || p2 == Type::Int) return Type::Int;
    else return Type::Char;
}

bool Type::isNumeric() const
{
    if (this == Type::Int && this == Type::Float) return true;
    else return false;
}

bool Type::isBool() const
{
    if (this == Type::Bool)return true;
    else return false;
}

bool Type::isChar() const
{
    if (this == Type::Char)return true;
    else return false;
}
