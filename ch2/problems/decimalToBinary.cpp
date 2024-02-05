#include <iostream>
#include <string>

/**
 * @brief 
 * 
 * @param decimal 
 * @param result 
 * @return std::string 
 */
std::string findBinary(int decimal, std::string result)
{
    if (decimal == 0) // base case
        return result;

    result = std::to_string(decimal % 2) + result;
    return findBinary(decimal / 2, result);
}


int main()
{
    int decimal;
    std::string result = "";
    std::cout << "Enter a decimal integer: ";
    std::cin >> decimal;

    std::cout << findBinary(decimal, result);
    std::cout << std::endl;
}