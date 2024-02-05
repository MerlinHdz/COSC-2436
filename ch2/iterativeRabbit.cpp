#include <iostream>


int iterativeRabbit(int n)
{
    // Initialize base cases:
    int previous = 1;   // Initially rabbit(1)
    int current = 1;    // Initially rabbit(2)
    int next = 1;       // rabbit(n); initial value when n is 1 or 2

    // Compute next rabbit values when n >= 3
    for (int i = 3; i <= n; i++)
    {
        // current is rabbit(i - 1), previous is rabbit(i - 2)
        next = current + previous;  // rabbit(i)
        previous = current;         // Get ready for next iteration
    }   // end for
    return next;
}   // end iterativeRabbit


int main()
{
    return 0;
}