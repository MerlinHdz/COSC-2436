/**
 * @file prefixEvaluator.cpp
 * @author Merlin Hernandez - Data Structures (74624)
 * @brief This program asks the user for a prefix algebraic expression and assumes the following:
 * That the expression is valid; That the expression only involves the binary operators (+, -, *, /)
 * And that the expression will contain single integer values
 * Then it evaluates the expression and prints the result.
*/

#include <iostream>
#include <string>
#include <cctype>
#include "ArrayStack.h"
using namespace std;

int evaluatePrefix(string);
int performOperation(int, int, char);

int main()
{
    string expression; // string to store user's expression
    string SENTINEL = "q";

    // Ask user for a prefix expression
    cout << "Enter prefix expression or q to quit: ";
    cin >> expression;

    while (expression != SENTINEL)
    {
        // Evaluate the expression and display result to user
        int result = evaluatePrefix(expression);
        cout << "= " << result << endl << endl;

        // Get next reading
        cout << "Enter prefix expression or q to quit: ";
        cin >> expression;
    }

    return 0;
}

/** evaluatePrefix
 * @brief This function utilizes an int stack to evaluate a prefix expression given as
 * a string. It loops through the expression in reverse order, pushing the digit characters
 * onto the stack (with their correct int values by doing - '0'), and pushing the result of
 * the operation when an operator is encountered (calling a separate function).
 * It then returns the top value in the stack - aka the result. 
 * 
 * @param exp a string representing a prefix expression
 * @return an integer representing the result of the operation
 */
int evaluatePrefix(string exp)
{
    // Create an array stack
    ArrayStack<int> stack;

    // Loop through expression in reverse 
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        // Check if character is an operand
        if (isdigit(exp[i]))
        {
            // push operand to the stack
            stack.push(exp[i] - '0'); // - '0' to get correct int value
        }
        else
        {
            // operator encountered, store and pop the top 2 items on stack
            // then push to stack the result of the expression based on operator (by calling performOperation)
            int op1 = stack.peek();
            stack.pop();

            int op2 = stack.peek();
            stack.pop();

            // Push result of operation to stack
            stack.push(performOperation(op1, op2, exp[i]));
        }
    }

    return stack.peek();
}


/** performOperation
 * @brief This function checks which operator was passed to it, and based on that char
 * it performs the respective operation on the two integer values. 
 * @pre the expression is valid, the operator is a binary operator, the operands are single int values
 * @param operand1 an integer value
 * @param operand2 an integer value
 * @param operator a char, ('+', '-', '*' or '/') representing an operator
 * @return int result: the resulting value from the operation
 */
int performOperation(int operand1, int operand2, char op)
{
    int result = 9;

    switch(op)
    {
        case '+':
            result =  operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
    }

    return result;
}
