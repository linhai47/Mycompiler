#include "Node.h"
#include <cstdlib> // 用于 exit(1)

int Node::labels = 0;
int Node::pending_label = -1;
void Node::error(const std::string& s) {
    /* std::cerr << "Error: " << s << std::endl;

    exit(1);*/
}

int Node::newlabel() {
    return ++labels;
}

void Node::emitlabel(int i) {
   /* cout << "Node emitlabel" << endl;*/
    std::cout << "L" << i << ":";
  
}

void Node::emit(const string &s)
{
     emitlabelIfPending();
     std::cout << "\t" << s << std::endl;
    
}

string Node::toString() const
{
    return "[Node] line " + std::to_string(lexline);
}

void Node::setPendingLabel(int label) {
    pending_label = label;
}

void Node::emitlabelIfPending() {
    /*cout << "pending_label:   " << pending_label << endl;*/
    if (pending_label != -1) {
        std::cout << std::endl << "L" << pending_label << ":" << std::endl;
        pending_label = -1;
    }
}