// Mycompiler.cpp: 定义应用程序的入口点。
//

#include "Mycompiler.h"

using namespace std;

int main()
{

    Lexer lex = Lexer();
    Parser parse = Parser(lex);
    parse.program();
	return 0;
}
