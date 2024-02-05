#include <iostream>


void solveTowers(int count, char source, char destination, char spare)
{
    if (count == 1)
    {
        std::cout << "Move top disk from pole " << source << " to pole "
        << destination << std::endl;
    }
    else
    {
        solveTowers(count - 1, source, spare, destination);
        solveTowers(1, source, destination, spare);
        solveTowers(count - 1, spare, destination, source);
    }   // end if
}   // end solveTowers


int main()
{
    solveTowers(4, 'A', 'B', 'C');
    return 0;
}