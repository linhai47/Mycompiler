#include "Parser.h"



void Parser::program()
{
    Stmt* s = block();
    int begin = s->newlabel(); 
    int after = s->newlabel(); 
    s->emitlabel(begin);  
    s->gen(begin, after);
    s->emitlabel(after);   
}

Stmt* Parser::block()
{
    match('{'); 
    Env* saveEnv = top;
    top = new Env(top);
    decls();
    Stmt* s = stmts();
    match('}'); 
    top = saveEnv;
    return s; 
}

void Parser::decls()
{
   
    while (look->tag == Tag::BASIC) {
        Type* p = type(); // 解析 int

        Word* tok = dynamic_cast<Word*>(look);
        if (!tok) error("Unexpected identifier");
        match(Tag::ID);

      
        while (look->tag == '[') {
            p = dims(p); 
        }

        Id* id = new Id(tok, p, used);
        top->put(tok, std::move(id));
        used += p->width;

        match(';');
    }

}

Type* Parser::type()
{
   
    Type* p = dynamic_cast<Type*>(look);
    
    if (!p) error("Type expected");
    match(Tag::BASIC);
  
 
    return p;          
}

Type* Parser::dims(Type* p)
{
    cout << "进入dims" << endl;
    match('[');

   
    Num* size1= dynamic_cast<Num*>(look);
    if (!size1) error("Number expected");
    match(Tag::NUM);
    int size = size1->value;

    match(']');

  
    if (look->tag == '[') {
        p = dims(p);
    }

    return new Array(size, p);
}

Stmt* Parser::stmts()
{
    
    if (look->tag == '}') {
        return Stmt::Null;
    }
    Stmt* first_stmt = stmt();
    Stmt* rest_stmts = stmts();
    return new Seq(std::move(first_stmt), std::move(rest_stmts));
}

Stmt* Parser::stmt()
{
    switch (look->tag)
    {
    case ';': {
        move();
        return Stmt::Null;
    }
    case Tag::IF: {
        move(); 
        match('(');
        auto cond = Bool(); 
        match(')');
        Stmt* then_stmt = stmt();

        
        if (look->tag != Tag::ELSE) {
            return new If(std::move(cond), std::move(then_stmt));
        }

        move();
        Stmt* else_stmt = stmt();
        return new Else(std::move(cond), std::move(then_stmt), std::move(else_stmt));
    }
    case Tag::WHILE: { 
        Stmt* saved_env = Stmt::Enclosing;

        move(); 
        match('(');
        auto condition = Bool();
        match(')');
        Stmt* loop_body = stmt();

        While* while_node = new While(std::move(condition), std::move(loop_body));

        Stmt::Enclosing = saved_env;
        return while_node;
    }
    case Tag::DO: { 
        Stmt* saved_env = Stmt::Enclosing;


        move(); 
        Stmt* loop_body = stmt();
        match(Tag::WHILE);
        match('(');
        auto condition = Bool();
        match(')');
        match(';');
        Do* do_node = new Do(std::move(loop_body), std::move(condition));


        Stmt::Enclosing = saved_env; 
        return do_node;
    }
    case Tag::BREAK: { 
        move(); 
        match(';');
        return new Break();
    }
    case '{': { 
        return block();
    }
    default: { 
        return assign();
    }
    }
}

Stmt* Parser::assign()
{
    Stmt* stmt;

  
    Token* t = look; 
    match(Tag::ID);


    Id* id = top->get(t);
    if (!id) {
        error(t->toString() + " undeclared");
    }

    if (look->tag == '=') {
        move();
        auto expr = Bool(); 
        stmt = new Set(std::move(id), std::move(expr));
    }
    else {

        Access* access = offset(std::move(id));
        match('=');
        auto expr = Bool();
        stmt = new SetElem(std::move(access), std::move(expr));
    }

    match(';'); 
    return stmt;
}


Expr* Parser::Bool()
{
    Expr* x = join();
    while (look->tag == Tag::OR) {
        Token* tok = look;
        move();
        x = new Or(tok, x, join()); 
    }
    return x;
}

Expr* Parser::join()
{
    Expr* x = equality();
    while (look->tag == Tag::AND) {
        Token* tok = look;
        move();
        x = new And(tok, x, equality()); 
    }
    return x;
}

Expr* Parser::equality()
{
    Expr* x = rel();
    while (look->tag == Tag::EQ || look->tag == Tag::NE) {
        Token* tok = look;
        move();
        x = new Rel(tok, x, rel()); 
    }
    return x;
}

Expr* Parser::rel()
{
    Expr* x = expr();
    switch (look->tag) {
    case '<':
    case Tag::LE:
    case Tag::GE:
    case '>': {
        Token* tok = look;
        move();
        return new Rel(tok, x, expr());
    }
    default:
        return x; 
    }
}

Expr* Parser::expr()
{
    Expr* x = term();
    while (look->tag == '+' || look->tag == '-') {
        Token* tok = look;
        move();
        x = new Arith(tok, x, term()); 
    }
    return x;
}

Expr* Parser::term()
{
    Expr* x = unary();
    while (look->tag == '*' || look->tag == '/') {
        Token* tok = look;
        move();
        x = new Arith(tok, x, unary());
    }
    return x;
}

Expr* Parser::unary()
{
    if (look->tag == '-') {
        move();
        return new Unary(&Word::minus, unary()); 
    }
    else if (look->tag == '!') {
        Token* tok = look;
        move();
        return new Not(tok, unary());
    }
    else {
        return factor();
    }
}

Expr* Parser::factor()
{
    Expr* x = nullptr;

    switch (look->tag) {
      /*  cout << "调用了factor" << endl;*/
    case '(': { 
        move();
        x = Bool();
        match(')');
        return x;
    }
    case Tag::NUM: { 
        x = new Constant(look, Type::Int);
        move();
        return x;
    }
    case Tag::REAL: {
        x = new Constant(look, Type::Float);
        move();
        return x;
    }
    case Tag::TRUE: { 
        x = Constant::True;
        move();
        return x;
    }
    case Tag::FALSE: { 
        x = Constant::False;
        move();
        return x;
    }
    case Tag::ID: {
        string var_name = look->toString();
        Id* id = top->get(look);
        if (!id) error(var_name + " undeclared");
        move();

        if (look->tag != '[') return id; 
        return offset(id); 
    }
    default: {
        error("syntax error in factor");
        return nullptr; 
    }
    }
}

Access* Parser::offset(Id* array_id) {
   /* std::cout << "Enter Offset" << std::endl;*/


    Type* current_type = array_id->type;
    Array* arr_type = dynamic_cast<Array*>(current_type);
    if (!arr_type) error("Trying to index a non-array");

    // 只处理一维数组，直接提取大小
    int array_size = arr_type->size;
    Type* t = arr_type->of;

    // 计算一维数组的步长
    int base_width = t->width;  // 最基本类型宽度，比如 int 为 4
    int stride = base_width;

  
    match('[');
    Expr* index = Bool();
    match(']');

    
    Expr* offset = new Arith(new Token('*'), index, new Constant(stride));

  
    return new Access(array_id, offset, t);
}
