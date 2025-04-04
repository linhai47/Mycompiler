#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>
using namespace std;
class Token{
public :
    Token(int t):tag(t){}
    Token() : tag(0) {}
    int getTag() {return tag;}

    virtual string toString() const {
        return std::string(1, static_cast<char>(tag));
    }
    bool operator==(const Token& other) const {
        return tag == other.tag;
    }
    virtual ~Token() {} // 添加虚析构函数
    const int tag;
};

namespace std {
    template <>
    struct hash<Token> {
        std::size_t operator()(const Token& t) const {
            return std::hash<int>()(t.tag); // 直接对 tag 进行哈希
        }
    };
}

#endif // TOKEN_H
