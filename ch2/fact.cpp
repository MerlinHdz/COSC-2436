#include <iostream>

/** Computes the factorial of the nonnegative integer n.
 @pre n must be greater than or equal to 0.
 @post None.
 @return The factorial of n; n is unchanged.*/
int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n-1);
}   // end fact



int main()
{
    int num;
    std::cout << "Enter number greater than 0: ";
    std::cin >> num;

    std::cout << fact(num) << std::endl;


    // This function call fits the model of a recursive function given in CH2
    // 1. One action of fact is to call itself.
    // 2. At each recursive call to fact, the integer whose factorial we need to compute
    // is diminished by 1
    // 3. The function handles the factorial of 0 differently, we know that fact(0) is 1. 
    // Thus, the base case occurs when n is 0;
    // 4. Given that n is nonnegative, item 2 of this list assures that you will always reach
    // the base case.
}


