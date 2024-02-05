#include <iostream>


/**
 * @brief 
 * 
 * @param base 
 * @param exponent 
 * @return int 
 */
int power(int base, int exponent)
{
    // Base case: when exponent is 0, any number raised to 0 is 1.
    if (exponent == 0)
    {
        return 1;
    }

    return base * power(base, exponent - 1);
}


int main()
{
    // Example usage
    int base = 5;
    int exponent = 3;
    std::cout << exponent << "";
    std::cout << power(2, 4);
    std::cout << std::endl;
    return 0;
}