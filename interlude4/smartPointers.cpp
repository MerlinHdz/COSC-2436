#include <iostream>
#include <memory>
using namespace std;


class myClass
{
public:
    myClass()
    {
        cout << "Constructor invoked" << endl;
    }
    ~myClass()
    {
        cout << "Destructor invoked" << endl;
    }
};

int main()
{
    // shared_ptr<myClass>shPtr1 = make_shared<myClass>();
    // cout << "Shared count: " << shPtr1.use_count() << endl;
    // shared_ptr<myClass>shPtr2 = shPtr1; 
    // cout << "Shared count: " << shPtr1.use_count() << endl;

    weak_ptr<int> weakPtr1;

    // making an additional scope
    {
        shared_ptr<int> shPtr1 = make_shared<int>(25);
        weakPtr1 = shPtr1;
    }

    return 0;
}