# Problem 2 - Date Object

A date consists of month, day and year. Consider the class Date of such dates. Suppose
that Date represents the month, day, and year as integers. For example, July 4, 1776, is
month 7, day 4, and year 1776.

- a. Write specifications for a method within Date that advances any given day by one
day. Include a statement of purpose, the preconditions and post-conditions, a
description of the arguments, and a description of any return value.

- b. Write a C++ Implementation of this method. Design and specify any other method
that you need. Include comments that will be useful to someone who will maintain
your implementation in the future.

[Date.cpp](Date.cpp)

## Statement of Purpose

The purpose of this method is to advance a given date by one day,
considering the day, month and year as integers. The method should
handle leap years and adjust the date accordingly.

## Preconditions

- The date provided is a valid date with a valid month, day and year.
- The date is within acceptable range of valid calendar dates.
- The month is in the range 1-12
- The day is in the range 1-31 (Depending on the month).
- The year is a positive integer.

## Post-conditions

- The method modifies the given Date object, advancing it by one day.
- If advancing by one date results in the next month, the month should be
updated accordingly, and the day reset to 1.
- If advancing the date results in the next year, the year should be updated
accordingly.
- Leap year rules are considered, ensuring the correct number of days in
February.

## Description of Arguments

- **month**: An integer in the range 1-12 representing the month
- **day**: An integer in the range (1-31) representing the day
- **year**: An positive integer representing the year of the date.

## Return Value

No return value for this method.
