#include <iostream>

/**
 * @brief Recursive function to count down from n to 1
 * 
 * @param n - an integer where n > 1
 * @return none
 */
void countDown(int n)
{
    if(n > 0)
    {
        // print current value of n
        std::cout << n << std::endl;
        countDown(n - 1);

    }
    // else do nothing

}


int main()
{
    int num = 0;
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    // Call recursive countDown function
    countDown(num);
    std::cout << std::endl;
}