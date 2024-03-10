# Chapter 5 - Recursion as a Problem-Solving Technique

## 5.2 Algebraic Expressions

| A recognition algorithm for prefix expressions

```pseudocode
// Finds the end of a prefix expression, if one exists
// Precondition: the substring of strExp from first to the end of the string contains no blank characters.
// Post-condition: Returns the index of the last character in the prefix expression that begins at
// index first of strExp, or -1 if no such prefix expression exists.
endPre(strExp: string, first: integer): integer
{
    last = strExp.length() - 1
    if (first < 0 or first > last)
        return -1

    ch = character at position first of strExp
    if (ch is an identifier)
        return first

    else if (ch is an operator)
    {
        // Find the end of the first prefix expression
        endPos = endPre(strExp, first + 1) // Point X

        // If the end of the first expression was found, find the end of the second
        if (endPos > -1)
            return endPre(strExp, endPos + 1) // Point Y
        else
            return -1
    }
    else
        return -1
}
```

| Now you can use **endPre** to determine whether a string contains a prefix expression as follows:  

```Pseudocode
// Sees whether a string contains a prefix expression
// Precondition: strExp contains a string with no blank characters
// Post-condition: Returns true if expression is in prefix form, false otherwise

isPrefix(strExp: string): boolean
{
    lastChar = endPre(strExp, 0)
    return (lastChar >= 0) and (lastChar == strExp.length() - 1)
}
```

The following function evaluates a prefix expression. This algorithm is simpler than one that evaluates  
infix expressions.  

```Pseudocode
// Returns the value of a given prefix expression
// Precondition: strExp is a string containing a prefix expression with no blanks. 
evaluatePrefix(strExp: string): float
{
    strLength = the length of strExp
    if (strLength == 1)
        return value of the identifier // Base case - single identifier
    else
    {
        op = strExp[0]  // strExp begins with an operator

        // Find the end of the first prefix expression -- will be the first operand
        endFirst = endPre(strExp, 1)

        // Recursively evaluate this first prefix expression
        operand1 = evaluatePrefix(strExp[1..endFirst])

        // Recursively evaluate the second prefix expression -- will be the second operand
        endSEcond = strLength - endFirst + 1
        operand2 = evaluatePrefix(strExp[endFirst + 1..endSecond]) 

        // Evaluate the prefix expression
        return operand1 op operand 2
    }
}
```

### 5.2.3 Postfix Expressions  

A grammar that defines the language for all postfix expressions is:  

```pseudocode
<postfix> = <identifier> | <postfix><postfix><operator>
<operator> = +|-|*|/
<identifier> = a|b|...|z
```

Here we shall develop an algorithm for converting a prefix expression to a postfix expression.  

```pseudocode
if (exp is a single letter)
    return exp
else
    return postfix(prefix1) * postfix(prefix2) * <operator>
```

The following function refines this algorithm

```pseudocode
// Converts a prefix expression to postfix form
// Precondition: The string preExp is a valid prefix expression with no blanks
// Post-condition: Returns the equivalent postfix expression
convertPreToPost(preExp: string): string
{
    preLength = the length of preExp
    ch = first character in preExp
    postExp = an empty string

    if (ch is a lowercase letter)
        // Base case - single identifier
        postExp = postExp * ch  // Append to end of postExp
    else // ch is an operator
    {
        // preExp has the form <operator><prefix1><prefix2>
        endFirst = endPre(preExp, 1) // Find the end of prefix1

        // Recursively convert prefix1 into postfix form
        postExp = postExp * convertPreToPost(preExp[1..endFirst])

        // Recursively convert prefix2 into postfix form
        postExp = postExp * convertPreToPost(preExp[endFirst + 1..preLength - 1])

        postExp = postExp * ch  // Append the operator to the end of postExp
    }
    return postExp
}
```

### 5.2.4 Fully Parenthesized Expressions

Most programming languages use infix notation. However, infix notation requires precedence rules, rules for association  
and parenthesis to avoid ambiguity between within the expressions.  

You can make precedence and association rules unnecessary by placing parenthesis around each pair  
of operands together with their operator, thereby avoiding ambiguity. A grammar for the language  
of all fully parenthesized infix expressions is:  

```pseudocode
<infix> = <identifier>|(<infix><operator><infix>)
<operator> = +|-|*|/
<identifier> = a|b|...|z
```

Although the grammar is simple, the language is rather inconvenient for programmers.

## 5.3 Backtracking

The strategy of retracing steps in reverse order and then trying a new sequence of steps is  
called **backtracking**.  

### 5.3.1 Searching for an Airline Route

Determine whether HPAir flies from one city to another.  

Imagine three input text files that specify all of the flight information for the airline as follows:  

* The names of cities that HPAir serves
* Pairs of city names, each pair representing the origin and destination of one of HPAir's flights.
* Pairs of city names, each pair representing a request to fly from some origin to some destination.  

The program should then produce output such as:

Request is to fly from Providence to San Francisco. HPAir flies form Providence to San Francisco.  
Request is to fly from Philadelphia to Albuquerque. Sorry. HPAir does not fly from Philadelphia  
to Albuquerque.  
Request is to fly from Salt Lake City to Paris. Sorry. HPAir does not serve Paris.  

```c++
// Discovers whether a sequence of flights from originCity to destinationCity exists
searchR(originCity: City, destinationCity: City): boolean
{
    Mark originCity as visited
    if (originCity is destinationCity)
        Terminate -- destination is reached
    else
        for (each unvisited city C adjacent to originCity)
            searchR(C, destinationCity)
}
```

The ADT flight map could include the following operations, given here in UML notation:  

```c++
// Reads flight information into the flight map
+readFlightMap(cityFileName: string, flightFileName: string): void

// Displays flight information
+displayFlightMap(): void

// Displays all cities that are adjacent to a given city.
+displayAdjacentCities(aCity: City): void

// Marks a city as visited
+markVisited(aCity: City): void

// Clears marks on all cities
+unvisitAll(): void

// Sees whether a city was visited
+isVisited(aCity: City): boolean

// Inserts a city adjacent to another city in a flight map.
+insertAdjacentCity(aCity: City, adjCity: City): void

// Returns the next unvisited city, if any, that is adjacent to a given city
// Returns a sentinel value if no unvisited adjacent city was found
+getNextCity(fromCity: City): City

// Tests whether a sequence of flights exists between two cities
+isPath(originCity: City, destinationCity: City): boolean
```

The latter operation **isPath** uses the **searchR** algorithm to make its determination. If the class  
Map is the implementation of the ADT flight map, its method isPath has the following implementation C++  
definition. Note that NO_CITY is a City object that Map defines as a constant for getNextCity to  
return in case it cannot find an unvisited adjacent city.  

```c++
bool Map::isPath(City originCity, City destinationCity)
{
    // Mark the current city as visited
    markVisited(originCity);

    bool foundDestination = (originCity == destinationCity);
    if (!foundDestination)
    {
        // Try a flight to each unvisited city
        City nextCity = getNextCity(originCity);
        while(!foundDestination && (nextCity != NO_CITY))
        {
            foundDestination = isPath(nextCity, destinationCity);
            if (!foundDestination)
                nextCity = getNextCity(originCity);
        }   // end while
    }   // end if

    return foundDestination;
}
```

### 5.3.2 The Eight Queens Problem

Consider an algorithm that places a queen in a column, given that you have placed queens correctly  
in the preceding columns. First, if there are no more columns to consider, you are finished; this  
is the base case. Otherwise, after you successfully place a queen in the current column, you need  
to consider the next column. That is, you need to solve the same problem with one fewer column;  
this is the recursive step.  

However, you do not know whether you can successfully place a queen in the current column.  
If you can, you recursively consider the next column. If you cannot place a queen in the current  
column, you need to backtrack, as has already been described.  

The following pseudocode describes the algorithm for placing queens in columns, given that the  
previous columns contains queens that cannot attack one another:  

```c++
// Places queens in eight columns
placeQueens(queen: Queen, row: integer, column: integer): boolean
{
    if (column > BOARD_SIZE)
        the problem is solved
    else
    {
        while (unconsidered squares exist in the given column and the problem is unsolved)
        {
            Find the next square in the given column that is 
            not under attack by a queen in an earlier column

            if (such a square exists)
            {
                Place a queen in the square

                // Try next column
                if (!placeQueens(a new queen, firstRow, column + 1))
                {
                    // No queen is possible in the next column
                    Remove the new queen
                    Move the last queen that was placed on the board
                    to the next row in that column
                }
                else
                    remove the new queen
            }
        }
    }
}
```

## 5.4 The Relationship Between Recursion and Mathematical Induction

A very strong relationship exists between recursion and mathematical induction.
Recursion solves a problem by specifying a solution to one or more base cases and then demonstrating how
to derive the same solution to a problem of an arbitrary size from the solutions to smaller problems of
the same type. Similarly, mathematical induction proves a property about the natural numbers
by proving the property about a base case - usually 0 or 1 - and then proving that the property
must be true for an an arbitrary natural number n if it is true for the natural numbers smaller than *n*.

Given these similarities, it is not surprising that induction is often employed to prove properties
about recursive algorithms. You can for example:

* Prove that an algorithm actually performs the task that you intended.
* Another use of mathematical induction is to prove that a recursive algorithm performs a certain amount
of work. (e.g. prove that solution to Towers of Hanoi makes exactly 2^N - 1 moves)

```C++
// The following pseudocode describes a recursive function that computes the factorial of a
// nonnegative integer n:
fact(n: integer): integer
{
    if (n is 0)
        return 1
    else
        return n * fact(n -1)
}

// You can prove that the function fact returns the values
factorial(0) = 0! = 1
factorial(n) = n! = n x (n-1) x (n-2) x ... x 1 if n > 0

// The proof is by induction on n.
```

### Basis

*Show that the property is true* for n = 0. That is, you must show that fact(0) returns 1. But
the result is simply the base case of the function: fact(0) returns 1 by its definition.

You now must establish that

|  **property is true for an arbitrary k => property is true for k + 1**

### Inductive hypothesis

*Assume that the property is true for n = k.* That is, assume that

|  **factorial(k) = k! = k x (k - 1) x (k - 2) x ... x 1**  

### Inductive conclusion

*Show that the property is true for n = k + 1.* That is, you must show that fact(k + 1) returns
the value

|  (k + 1) x k x (k - 1) x (k - 2) x ... x 2 x 1

By definition of the function fact, fact (k + 1) returns the value  

|  (k + 1) x factorial(k)  

But by the inductive hypothesis, fact(k) returns the value  

| k x (k - 1) x (k - 2) x ... x 2 x 1  

Thus, fact(k + 1) returns the value  

|   (k + 1) x (k - 1) x (k - 2) x ... x 2 x 1  

which is what you needed to show.  

The inductive proof is thus complete.  
