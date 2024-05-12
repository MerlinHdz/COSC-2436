
#include <iostream>
#include <string>
#include "BinarySearchTree.h"

// EmployeeInfo class definition
class EmployeeInfo {
private:
    int id;
    std::string name;
    std::string position;

public:
    // Constructor
    EmployeeInfo(int id, const std::string& name)
        : id(id), name(name), position(position) {}

    // Getter methods
    int getID() const { return id; }
    std::string getName() const { return name; }
};


int main() {
    // Create a binary search tree of EmployeeInfo objects
    BinarySearchTree<EmployeeInfo> employeeTree;

    // Add some employees to the tree
    employeeTree.add(EmployeeInfo(6702, "James B W Bevis"));
    employeeTree.add(EmployeeInfo(1255, "Romney Wordsworth"));
    employeeTree.add(EmployeeInfo(1071, "Revis Jacara"));
    employeeTree.add(EmployeeInfo(2390, "Clegg Forbes"));
    employeeTree.add(EmployeeInfo(1558, "Kalin Tros"));
    employeeTree.add(EmployeeInfo(7406, "Archibald Beechcroft"));
    employeeTree.add(EmployeeInfo(7562, "Penthor Mul"));
    employeeTree.add(EmployeeInfo(3004, "Bartlet Finchley"));
    employeeTree.add(EmployeeInfo(4922, "Latham Bine"));
    employeeTree.add(EmployeeInfo(8483, "Jeff Myrtlebank"));
    

    


    return 0;
}
