# Chapter 2 Recursion: The Mirrors

- A recursive function calls itself
- Each recursive call solves an identical, but smaller problem.
- A test for the base case enables the recursive calls to stop.


**Four questions for constructing recursive solutions**

1. How can you define the problem in terms of a smaller problem of the same type?
2. How does each recursive call diminish the size of the problem?
3. What instance of the problem can serve as the base case?
4. As the problem diminishes, will you reach this base case?


## 2.2.1 A Recursive Valued Function: The Factorial of *n*

This is a good first example because its recursive solution is easy to understand and
nearly fits the mild described earlier. However, because the problem has a simple and 
efficient iterative solution, you should not use the recursive solution in practice.

*factorial(n)* = n x (n-1) x (n-2) x ... x 1 for an integer n > 0      
*factorial(n)* = 1   
  
The factorial of a negative integer is undefined.
To define factorial(n) recursively, you first need to define factorial(n) in terms of the factorial of
a small number. To do so, simply observe that the factorial of n is equal to n * (n - 1)  

The base case for the factorial function is factorial(0), which we know is 1.
Because n originally is greater than or equal to zero and each call to factorial decrements n
by 1, you will always reach the base case.