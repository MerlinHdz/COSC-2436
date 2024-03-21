# Chapter 10 - Algorithm Efficiency

## Traversing a Linked-List

```c++
auto curPtr = headPtr;          // 1 assignment
while (curPtr != nullptr)       // n + 1 comparisons
{
    std::cout << curPtr->getItem() << std::endl; // n writes
    curPtr = curPtr->getNext();                  // n assignments
}   // end while
```

If we have n nodes, these statements require n+1 assignments, n+1 comparisons, and n write  
operations. If each assignment, comparison, and write operation requires, respectively, a, c, and  
w time units, the statements require (n + 1)x(a + c) + n x w time units. Thus, the time required  
to write n nodes is proportional to n.

## The Towers of Hanoi Problem
