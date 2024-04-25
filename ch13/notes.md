# Chapter 13 Queues and Priority Queues

Queues are cool.

## Simple Applications of the ADT Queue

A queue can retain characters in the order in which you typed them.

```c
// Read a string of characters from a single line of input into a queue
aQueue = a new empty queue
while (not end of line)
{
    Read a new character into ch
    aQueue.enqueue(ch)
}
```

Once the characters are in a queue, the system can process them as necessary. For example,
if you typed the integer 247 -- without any mistakes, but possibly preceded or followed by
blanks -- the queue would contain digits and possibly blanks. The system could convert
the digits 2, 4 and 7 into the decimal value 247 by computing 10 x (10 x 2 + 4) + 7.

The following pseudocode function performs the conversion in general:

```
// Converts digits in a queue aQueue into a decimal integer.
getInteger(aQueue: Queue): integer
{
    // Get first digit, ignoring any leading blanks
    do
    {
        ch = aQueue.peekFront()
        aQueue.dequeue()
    } while (ch is blank)
    // Assertion: ch contains first digit

    // Compute the integer n from digits in queue
    n = 0
    done = false

    do 
    {
        n = 10 * n + (integer that ch represents)
        done = aQueue.isEmpty()
        if (!done)
        {
            ch = aQueue.peekFront()
            aQueue.dequeue()
        }
        while (!done and ch is a digit)
    }
    return n
}
```

### Recognizing Palindromes

You can use a queue in conjunction with a stack to recognize palindromes

As you traverse a string from left to right, you can add each character to both a queue and a
stack. 

The first character in the string is at the front of the queue and the last character in the
string is at the top of the stack. Thus, characters removed from the stack will occur in the 
opposite order.

Knowing this, you can compare the characters at the front of the queue and the top of the stack.
If the two characters are the same, you can remove them. You repeat this process until either the
stack and the queue become empty, in which case the original string is a palindrome, or the two
characters are not the same, in which case the string is not a palindrome.

the following is a pseudocode version of a non-recursive algorithm for the language
of palindromes:

```c
// Test whether some string is a palindrome
isPalindrome(someString: string): boolean
{
    // Create an empty queue and an empty stack
    aQueue // new empty queue
    aStack // new empty stack

    // Add each character of the strong to both the queue and the stack
    length = length of someString
    for (i = i through length)
    {
        nextChar = ith character of someString
        aQueue.enqueue(nextChar)
        aStack.push(nextChar)
    }

    // Compare the queue characters with the stack characters
    charactersAreEqual = true
    while (aQueue is not empty and charactersAreEqual)
    {
        queueFront = aQueue.peekFront()
        stackTop = aStack.peek()
        if (queueFront == stackTop)
        {
            aQueue.dequeue()
            aStack.pop()
        }
        else
            charactersAreEqual = false
    }
    return charactersAreEqual
}
```


## The ADT Priority Queue

A **priority value** indicates, for example, a patient's priority for treatment  
or a task's priority for completion. What quantity should you use for  
this priority value? Many reasonable possibilities exist, including a  
simple ranking form 1 to 10. Let's arbitrarily decide that the largest  
priority value indicates the highest priority. The priority value becomes  
a part of the item that you insert into an ADT. You then ask the ADT for the item that has the highest priority.

It provides the following operations:

* Test whether a priority queue is empty
* Add a new entry to the priority queue in its sorted position based on priority value.
* Remove from the priority queue the entry with the highest priority value.
* Get the entry in the priority queue with the highest priority value.

Although priority queues and sorted lists both order their entries by values, these ADTs differ in how  
their removal operations behave. When you remove an entry from a priority queue, you get the entry  
with the highest priority value. In contrast, you can remove any entry from a sorted list.  

UML "diagram" for the class PriorityQueue

```
+isEmpty(): boolean
+enqueue(newEntry: ItemType): boolean
+dequeue(): boolean
+peekFront(): ItemType
```

### Tracking Your Assignments

Using a priority queue, we can organize these assignments in the order in which we should complete them.  
Suppose that the we order the assignments by their due dates. We can define a class **Assignment** of tasks  
that includes a data field **date** representing the task's due date.

UML "diagram" for the class

```
course - the course code
task - a description of the assignment
date - the due date

+getCourseCode(): string
+getTask(): string
+getDueDate(): string
```

The following pseudocode shows how you could use a priority queue to organize your assignments and  
other responsibilities so that you know which one to complete first:  

```c
assignmentLog = a new priority queue using due date as the priority value
project = a new instance of Assignment
essay = a new instance of Assignment
quiz = a new instance of Assignment
errand = a new instance of Assignment

assignmentLog.enqueue(project)
assignmentLog.enqueue(essay)
assignmentLog.enqueue(quiz)
assignmentLog.enqueue(errand)

cout << "I should do the following first: "
cout << assignmentLog.peekFront()
```

## 13.4 Application: Simulation

**Simulation** --a major application area of computers--is a technique for modeling the behavior of both  
natural and human-made systems.  

### A problem to solve

Ms. Simpson, president of the First City Bank of Springfield, has heard her customers complain about
how long they have to wait for service at some branch.

We decided we want our simulation to determine:

* The average time a customer waits before receiving service from the current single teller
* The decrease in customer wait time with each new teller added

### Simulation time and events

Central to a simulation is the concept of simulated time. Envision a stopwatch that measures time  
elapsed during a simulation. 

To gather the information you need, you run this simulation for a specified period of simulated time.  
During the course of the run, you need to keep track of certain statistics, such as the average time a  
customer has to wait for service.  

