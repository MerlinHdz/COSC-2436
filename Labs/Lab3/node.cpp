#include "Node.h"

// Constructor
Node::Node()
{
    next = nullptr;
    category = "";
    line = "";
}

// Destructor
Node::~Node()
{
}

// Accessors
std::string Node::getCategory() const {
    return category;
}

std::string Node::getLine() const {
    return line;
}

Node* Node::getNext() const {
    return next;
}

// Mutators
void Node::setCategory(const std::string& newCategory) {
    category = newCategory;
}

void Node::setLine(const std::string& newLine) {
    line = newLine;
}

void Node::setNext(Node* newNext) {
    next = newNext;
}
