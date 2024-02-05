#include <iostream>
#include <string>
using namespace std;



class Student
{
    private:
        string studentName;
        int studentID;

    public:

        // Setters/Mutators
        void setData(string name, int ID); // Prototype setter

        // Getters/Accessors
        string getName()
        {
            return studentName;
        }

        int getStudentID()
        {
            return studentID;
        }

        // Constructor prototype
        Student();
};


// Setter definition
void Student::setData(string name, int ID)
{
    studentName = name;
    studentID = ID;
}

// Constructor Definition
Student::Student()
{
    studentName = "";
    studentID = 0;
}


int main()
{
    return 0;
}