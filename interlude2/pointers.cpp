#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    float c = 3.4;

    int* b;

    b = &a;

    cout << "a: " << a << " address is " << &a << endl;
    cout << "a through b: " << *b; // dereferencing the pointer
    cout << " b is: " << b << endl;

    cout << endl;
    return 0;
}