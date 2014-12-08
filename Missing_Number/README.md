
Description
====================

Given an array containing all numbers from 1 to N with the exception of one print the missing number to the standard output.

** Example input:
array: 5 4 1 2
** Example output:
3

** Expected complexity needs to be O(n)

Algorithm used :
================

We will go trhough the table, and we will compute the sum of all the elements.
Then we will compute the sum of all the numbers from 1 to n.
The difference is the missing number.

    ### Introducing a bit-array will add an extra space of O(n) which is not sufficient for most of the cases.

Bonus questions:
----------------

**Q1** That is correct, but now how would you do this if TWO numbers are missing?
**Q2** What if there are duplicates.
**Q3** How do you find if there are exactly k numbers missiong.

Answers (P)
-------------------

**Q1/Q3** We need to solve the followign equation.
`k1 + k2 = x`
`k1^2 + k2^2 = y`

We also know the :

`S = 1 + 2 + .... + n`
`E = 1^2 + 2^2 + .... + n^2`

where S is the expected sum, and E is the xpected power.

The sum of the elements in the arrays is :

`S1 = S - x`
`E1 = E - y`

so we have two equations with two unknowns, therefore it can be solved.

The same can be expanded until k missing numbers.

