#include <iostream>
#include <string>

void writeBackward(std::string s)
{
    int length = s.size(); // Length of string
    if (length > 0)
    {
        // Write the last character
        std::cout << s.substr(length - 1, 1);

        // Write the rest of the string backward
        writeBackward(s.substr(0, length - 1)); // Point A
    } // end if
    // length == 0 is the base case - do nothing
}   // end writeBackward


int main()
{
    std::string toReverse; // declare a string
    std::cout << "Enter a string: ";
    std::cin >> toReverse; // store user input in previously declared string

    writeBackward(toReverse); // reverse recursively (display)
    std::cout << std::endl;
}