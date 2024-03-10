# Chapter 6 Stacks

The "read and correct" algorithm

```c
while (not end of line)
{
    Read a new character ch
    if (ch is not a '<--')
        Add ch to the ADT
    else if (the ADT is not empty)
        Remove from the ADT and discard the item that was added most recently
    else
        ignore the '<--'
}
```

Operations on the ADT:

* Add new item to the ADT
* Remove from the ADT and discard the item that was added most recently
* See whether the ADT is empty
* Get a copy of the item that was added to the ADT most recently

The write-backward algorithm

```c
// Display the line in reverse order
while (the ADT is not empty)
{
    Get a copy of the item that was last added to the ADT and assign it to ch
    Display ch
    Remove from the ADT and discard the most recently added item
}
```

The refined algorithms

```c
// Reads an input line, recognizing the character '<--' as a backspace that erases the
// previously typed character
// Returns a stack of the corrected characters read
readAndCorrect(): Stack
{
    aStack = a new empty stack
    Read newChar

    while (newChar is not the end-of-line symbol)
    {
        if (newChar is not '<--')
            aStack.push(newChar)
        else if (!aStack.isEmpty())
            aStack.pop()
        Read newChar
    }
    return aStack
}

// Displays the input line in reverse by writing the contents of aStack
displayBackward(aStack: Stack)
{
    while (!aStack.isEmpty())
    {
        newChar = aStack.peek()
        aStack.pop()
        Write newChar
    }
    Advance to new line
}
```

| **Axioms (Optional)**

An axiom is a mathematical rule

*A newly created Stack is empty*  
is an axiom because it is true for all newly created stacks.

We can state this axiom succinctly in terms of the ADT stack operations as follows, if we represent a newly created stack by the  
pseudocode expression Stack():

| (Stack()).isEmpty() = true  

| (aStack.push(newItem)).pop() => aStack

## Simple Uses of a Stack

This section presents two rather simple examples for which the LIFO property of stacks is appropriate.  

### 6.2.1 Checking for Balanced Braces

The solution requires that you keep track of each unmatched "{" and discard one each time you encounter a "}".  
One way to perform this task is to push each "{" encountered onto a stack and pop one off each time you  
encounter a "}".  

| A detailed pseudocode solution to check a string for balanced braces.  

```C
// Checks the string aString to verify that braces match.
// Returns true if aString contains matching braces, false otherwise.
checkBraces(aString: string): boolean
{
    aStack = a new empty stack
    balancedSoFar = true
    i = 0   // Tracks character position in string

    while (balancedSoFar and i < length of aString)
    {
        ch = character at position i in aString
        i++

        // Push an open brace
        if (ch is a '{')
            aStack.push('{')

        // Close brace
        else if (ch is a '}')
        {
            if (!aStack.isEmpty())
                aStack.pop()    // Pop a matching open brace
            else    // No matching open brace
                balancedSoFar = false
        }
        // Ignore all characters other than braces
    }

    if (balancedSoFar and aStack.isEmpty())
        aString has balanced braces
    else
        aString does not have balanced braces

}   
```

### 6.2.2 Recognizing Strings in a Language

Consider the problem of recognizing whether a particular string is in the language

```pseudocode
L = {s$s' : s is a possibly empty string of characters other than $, s' = reverse(s)}
```

For example, the strings A$A, ABC$CBA, and $ are in the L, but AB$AB and ABC$CB are not.  

Suppose you traverse the first half of the string and push each character onto a stack. When you reach the $  
you can undo the process: For each character in the second half of the string, you pop a character off the stack.  
However, you must match the popped character with the current character in the string to ensure that the second  
half of the string is the reverse of the first half.  

The stack must be empty when - and only when - you reach the end of the string; otherwise, one "half" of the string  
is longer than the other, and so the sting is not in L.  

To avoid unnecessary complications, assume that aString contains exactly one $.  

```c
// Checks the string aString to verify that it is in the language L
// Returns true if aString is in L, false otherwise
recognizeString(aString: string): boolean
{
    aStack = a new empty stack

    // Push the characters that are before $ (that is, the characters in s) onto the stack 
    i = 0
    ch = character at position i in a aString
    while (ch is not a '$')
    {
        aStack.push(ch)
        i++
        ch = character in position i in aString
    }

    // Skip the $
    i++

    // Match the reverse of s
    inLanguage = true
    while (inLanguage and i < length of aString)
    {
        if (!aStack.isEmpty())
        {
            stackTop = aStack.peek()
            aStack.pop()
            ch = character at position i in string
            if (stackTop equals ch)
                i++ // Characters match
            else
                inLanguage = false // Characters don't match (top of stack is not ch)
        }
        else
            inLanguage = false // Stack is empty (first half of the string is shorter than second half)
    }

    if (inLanguage and aStack.isEmpty())
        aString is in language
    else
        aString is not in language
}
```

## 6.3 - Using Stacks with Algebraic Expressions

The strategy we shall adopt here is first to develop an algorithm for evaluating postfix expressions  
and then to develop an algorithm for transforming an infix expression into an equivalent postfix expression.  

### 6.3.1 Evaluating Postfix Expressions

Recall that an operator in a postfix expression applies to the two operands that immediately  
precede it. Thus, the calculator must be able to retrieve the operands entered most recently. The  
ADT stack provides this capability. Each time you enter an operand, the calculator  
pushes it onto a stack. When you enter an operator, the calculator applies it to the top two  
operands on the stack, pops the operands from the stack, and pushes the result of the operation  
onto the stack.  

To avoid issues that cloud the algorithm with programming details, assume that:  

* The string is syntactically correct
* No urinary operators are present
* No exponentiation operators are present
* Operands are single lowercase letters that represent integer values.

The pseudocode for this algorithm is then

```c
for (each character ch in the string)
{
    if (ch is an operand)
        Push the value of the operand ch onto the stack
    else
    {
        // Evaluate and push the result
        operand2 = top of stack
        Pop the stack

        operand1 = top of stack
        Pop the stack

        result = operand1 op operand2
        Push the result to the stack
    }
}
```

### 6.3.2 Converting Infix Expressions to Equivalent Postfix Expressions

You will be able to evaluate an infix expression if you can convert it into an equivalent postfix expression.  

First draft.

```c
Initialize postfixExp to the empty string
for (each character ch in the infix expression)
{
    switch(ch)
    {
        case ch is an operand:
            Append ch to the end of postfixExp
            break
        case ch is an operator:
            Save ch until you know where to place it
            break
        case ch is a '(' or a ')':
            Discard ch
            break
    }
}
```

Parenthesis are one of the factors that determine the placement of the operators in the  
postfix expression. The other factors are precedence and left-to-right association.  

...

| A pseudocode algorithm that converts an infix expression to postfix form

```c
for (each character ch in the infix expression)
{
    switch(ch)
    {
        case operand:   // Append operand to end of postfix expression - step 1
            postfixExp = postfixExp * ch
            break
        case '(':       // Save '(' on stack - step 2
            operatorStack.push(ch)
            break
        case operator:  // Process stack operators of greater precedence - step 3
            while (!operatorStack.isEmpty() and operatorStack.peek() is not a '(' and 
                   precedence(ch) <= precedence(operatorStack.peek()))
            {
                Append operatorStack.peek() to the end of postfixExp
                operatorStack.pop()
            }
            operatorStack.push(ch) // Save the operator
            break
        case ')':   // Pop stack while matching '(' - step 4
            while (operatorStack.peek() is not a '(')
            {
                Append operatorStack.peek() to the end of postfixExp
                operatorStack.pop()
            }
            operatorStack.pop() // remove the parenthesis
            break
    }
}

// Append to postfixExp the operators remaining in the stack - step 5
while (!operatorStack.isEmpty())
{
    Append operatorStack.seek() to the end of postfixExp
    operatorStack.pop()
}
```

## 6.4 - Using a Stack to Search a Flight Map

First notice that when the algorithm backtracks from a city C, it must retreat to the city  
that it visited most recently before C. This observation suggests that you maintain the  
sequence of visited cities in a stack.  

```c
cityStack = a new empty stack
Clear marks on all cities

cityStack.push(originCity) // Push origin city onto cityStack
Mark the origin as visited

while (a sequence of flights from the origin to the destination has not been found)
{
    // Loop invariant: The stack contains a directed path from the origin city at
    // the bottom of the stack to the city at the top of the stack
    if (no flights exist from the city on the top of the stack to unvisited cities)
        cityStack.pop() // Backtrack
    else
    {
        Select an unvisited destination city C for a flight from the city on the top of the stack
        cityStack.push(C)
        Mark C as visited
    }
}
```

The algorithm can reach a negative conclusion only after it has exhausted all possibilities  
-- that is, after the algorithm has backtracked to the origin and has no unvisited cities to  
fly to from the origin. At that point, the algorithm will pop the origin city from the stack  
and the stack will become empty.  

With this refinement, the algorithm appears as follows:  

```c
// Searches for a sequence of flights from originCity to destinationCity
searchS(originCity: City, destinationCity: City): boolean
{
    cityStack = a new empty stack
    Clear marks on all cities

    cityStack.push(originCity) // Push origin onto the stack
    Mark the origin as visited

    while (!cityStack.isEmpty() and destinationCity is not at the top of the stack)
    {
        // Loop invariant: The stack contains a directed path from the origin city at
        // the bottom of the stack to the city at the top of the stack
        if (no flights exist from the city on the top of the stack to unvisited cities)
            cityStack.pop() // Backtrack
        else
        {
            Select an unvisited destination city C for a flight from the city on the top of the stack
            cityStack.push(C)
            Mark C as visited
        }
    }

    if (cityStack.isEmpty())
        return false // No path exists
    else
        return true // Path exists
}
```

ADT flight map operations

```c

// Marks a city as visited
markVisited(aCity: City): void

// Clears marks on all cities
unvisitAll(): void

// Returns the next unvisited city, if any, that is adjacent to a given city.
// Returns a sentinel value if no unvisited adjacent city was found.
getNextCity(fromCity: City): City

// Tests whether a sequence of flights exists between two cities.
isPath(originCity: City, destinationCity: City): boolean
```

Assuming that the class Map implements the ADT flight map and the class Stack implements  
the stack operations, the definition of Map's method isPath is as follows and uses the  
searchS algorithm. As we mentioned in Chapter 5, NO_CITY is a City object that Map  
defines as a constant for getNextCity to return in case it cannot find an unvisited adjacent  
city.  

C++ implementation of searchS

```c++
/** Tests whether a sequence of flights exists between two cities.
 *  Non-recursive stack version.
 * @pre originCity and destinationCity both exist in the flight map.
 * @post Cities visited during the search are marked as visited in the flight map.
 * @param originCity The origin city.
 * @param destinationCity The destination city
 * @return True if a sequence of flights exists from originCity to destinationCity
 * otherwise false. */
bool Map::isPath(City originCity, City destinationCity)
{
    Stack cityStack;
    unvisitAll(); // Clear marks on all cities

    // Push origin city onto cityStack and mark it as visited
    cityStack.push(originCity);
    markVisited(originCity);

    City topCity = cityStack.peek();
    while(!cityStack.isEmpty() && (topCity != destinationCity))
    {
        // The stack contains a directed path from the origin city
        // at the bottom of the stack to the city at the top of the stack

        // Find an unvisited city adjacent to the city on the top of the stack
        City nextCity = getNextCity(topCity);

        if (nextCity == NO_CITY)
            cityStack.pop(); // No city found; backtrack
        else
        {
            cityStack.push(nextCity);
            markVisited(nextCity);
        }   // end if

        if (!cityStack.isEmpty())
            topCity = cityStack.peek();
    }   // end while

    return !cityStack.isEmpty();
}   // end isPath
```
