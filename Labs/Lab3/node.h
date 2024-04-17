/** @file Node.h */
#ifndef NODE_
#define NODE_

#include <string>

class Node
{
private:
    std::string category; // the category of the line
    std::string line;     // line from a file (string)
    Node* next;           // raw pointer to a Node

public:
    // Constructor
    Node();

    // Accessors
    std::string getCategory() const;
    std::string getLine() const;
    Node* getNext() const;

    // Mutators
    void setCategory(const std::string& newCategory);
    void setLine(const std::string& newLine);
    void setNext(Node* newNext);

    // Destructor
    ~Node();
};

#include "Node.cpp"
#endif
