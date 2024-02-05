#include <iostream>


/**
 * @brief Computes the number of groups of k out of n things.
 * @pre n and k are nonnegative integers
 * @post none
 * 
 * @param n The given number of things
 * @param k The given number to choose
 * @return g(n, k) 
 */
int getNumberOfGroups(int n, int k)
{
    if ( (k == 0) || (k == n) )
        return 1;
    else if (k > n)
        return 0;
    else
        return getNumberOfGroups(n - 1, k - 1) + getNumberOfGroups(n - 1, k);
}   // end getNumber of Groups




int main() {
    // Example usage
    int n, k;
    std::cout << "Enter the total number of things (n): ";
    std::cin >> n;
    std::cout << "Enter the number of things to choose (k): ";
    std::cin >> k;

    // Validate input
    if (n < 0 || k < 0) {
        std::cout << "Invalid input. Please enter nonnegative values.\n";
        return 1;
    }

    // Calculate and display the result
    int result = getNumberOfGroups(n, k);
    std::cout << "Number of groups of " << k << " out of " << n << ": " << result << std::endl;

    return 0;
}
