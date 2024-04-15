/** @file node.h */
#include <string>

class Node
{
private:
    std::string category;
    std::string line;
    Node* next;
public:
    Node();

    // Mutator functions
    void setCategory(const std::string aCategory);
    void setLine(const std::string aLine);
    void setNext(Node* nextNodePtr);

    // Accessor functions
    std::string getCategory() const;
    std::string getLine() const;
    Node* getNext() const;

};
#include "node.cpp"
