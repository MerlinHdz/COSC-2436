/**
 * @file main.cpp
 * @author Merlin Hernandez COSC-2436-005
 * @brief 
 */
#include <iostream>
#include <string>
#include "BinarySearchTree.h"


class EmployeeInfo {
private:
    int ID;
    std::string employeeName;

public:
    // Constructors
    EmployeeInfo() : ID(0), employeeName("") {}
    EmployeeInfo(int id, const std::string& name) : ID(id), employeeName(name) {}

    // Getter methods
    int getID() const { return ID; }
    std::string getEmployeeName() const { return employeeName; }

    // Overloaded operators
    bool operator<(const EmployeeInfo& other) const {
        return ID < other.getID();
    }

    bool operator>(const EmployeeInfo& other) const {
        return ID > other.getID();
    }

    bool operator==(const EmployeeInfo& other) const {
        return ID == other.getID();
    }
};


// Function prototypes
void displayMenu();
int getMenuOption();
void searchForID(BinarySearchTree<EmployeeInfo>& tree);
void displayTree(BinarySearchTree<EmployeeInfo>& tree);
void addEmployee(BinarySearchTree<EmployeeInfo>& tree);
void removeEmployee(BinarySearchTree<EmployeeInfo>& tree);

int main() {
    // Create a binary search tree of EmployeeInfo objects
    BinarySearchTree<EmployeeInfo> employeeTree;

    // Insert some EmployeeInfo objects into the tree
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


    // Main Loop
    int menuOption;
    menuOption = getMenuOption();

    while (menuOption != 5)
    {
        switch(menuOption)
        {
            case 1:
                std::cout << "Search for an ID\n";
                searchForID(employeeTree);
                break;
            case 2:
                displayTree(employeeTree);
                break;
            case 3:
                std::cout << "Add Employee\n";
                addEmployee(employeeTree);
                break;
            case 4:
                std::cout << "Remove Employee\n";
                break;
            case 5:
                std::cout << "Exit\n";
                break;
        }

        // get user's choice for next iteration
        menuOption = getMenuOption();
    }

    return 0;
}



void displayMenu()
{
	std::cout << "1. Search for an ID\n";
	std::cout << "2. Display Tree\n";
	std::cout << "3. Add Employee\n";
	std::cout << "4. Remove Employee\n";
	std::cout << "5. Exit\n";
    std::cout << std::endl;
}

int getMenuOption()
{
    int choice = 0;
    displayMenu();

    // Get user input
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Validate user input 
    while (choice < 1 || choice > 5)
    {
        std::cout << "Invalid choice. Try again\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
    }
    return choice;
}   // end getMenuOption


void searchForID(BinarySearchTree<EmployeeInfo>& tree) {
    int id;
    std::cout << "Enter ID to search for: ";
    std::cin >> id;

    EmployeeInfo employee(id, ""); 

    if (tree.contains(employee)) {
        EmployeeInfo foundEmployee = tree.getEntry(employee);
        std::cout << "Employee found\n";
        std::cout << "ID: " << foundEmployee.getID() << ", Name: " << foundEmployee.getEmployeeName() << std::endl << std::endl;
    } else {
        std::cout << "Employee not found\n";
    }
}


void displayTree(BinarySearchTree<EmployeeInfo>& tree) {
    std::cout << "-- Employee Tree  --\n";
    tree.inorderTraverse([](EmployeeInfo& employee) {
        std::cout << "ID: " << employee.getID() << ", Name: " << employee.getEmployeeName() << std::endl;
    });
    std::cout << std::endl;
}

void addEmployee(BinarySearchTree<EmployeeInfo>& tree) {
    int id;
    std::string name;
    std::cout << "Enter ID: ";
    std::cin >> id;
    
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    EmployeeInfo employee(id, name);
    tree.add(employee);
    std::cout << "Employee added\n\n";
}

void removeEmployee(BinarySearchTree<EmployeeInfo>& tree) {
    int id;
    std::cout << "Enter ID to remove:";
    std::cin >> id;

    EmployeeInfo employee(id, "");
    if (tree.remove(employee)) {
        std::cout << "Employee removed\n";
    } else {
        std::cout << "Employee not found\n";
    }
}