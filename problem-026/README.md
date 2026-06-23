# Project Euler — Problem 26: Reciprocal Cycles

 A C++ solution to **Project Euler Problem 26**: finding the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

## Problem summary
```
For unit fractions 1/d, the decimal expansion can either terminate (e.g., 1/2 = 0.5) or repeat periodically (e.g., 1/3 = 0.(3)). The task is to find the denominator d < 1000 for which the decimal representation of 1/d has the longest repeating cycle.
```

## How the solution works (high-level)

- The program simulates long division for 1/d  
- tracks remainders to detect when the decimal expansion begins repeating. 
- When a remainder repeats, the digits between the first and second occurrence of that remainder form the recurring cycle.

Key idea:

    During long division, the next decimal digit depends only on the current remainder.

    If a remainder reappears, the cycle has started again; the distance between positions gives the cycle length.

## Code logic

**Function: Todecimal(long long den)**

    Simulates converting 1/den to a decimal string and detects the recurring cycle length.

    Steps:

        Start dividing 1 by den: integer part is 1/den (will be 0 for den > 1). Append ".".

        Keep the remainder rem = 1 % den.

        Use an unordered_map to record the position in the output string where each remainder first appears.

        In each iteration:

            If current remainder was seen before, insert "(" at its recorded position and append ")" to mark the repeating portion; break.

            Otherwise record current remainder with the current result string length (this sets where the next digit will be placed).

            Multiply remainder by 10, compute next digit rem/den, append it, and update rem = rem % den.

        Finally, the function extracts the substring that starts from "(" and computes its length minus 2 (to exclude the parentheses). That is returned as the recurring cycle length.

**Main:**

    Iterate d from 2 to 1000 (inclusive).

    Call Todecimal(d) to get the cycle length for 1/d.

    Track the maximum cycle length and corresponding denominator.

    Print the denominator that produces the longest recurring cycle.

Example behavior

    For d = 3, the function will detect rem = 1 → rem*10 = 10 → digit 3, rem becomes 1 again; cycle length = 1 (the digit 3).

    For d = 7, 1/7 = 0.(142857), cycle length = 6.

## Time and space complexity

For a single denominator d, 
    the long division loop can run at most d iterations because there are at most d distinct nonzero remainders (0..d-1). So the per-denominator time is O(d).

The main loop runs for n denominators (n = 1000 here), giving worst-case time **O(n^2)**. For n = 1000 this is easily tractable.

- **Space**: unordered_map stores at most d entries per call, so **O(d)** extra space per invocation.


### simplified Todecimal (conceptual):

    rem = 1% den

    pos = 0

    while rem != 0 and rem not seen:

        seen[rem] = pos

        rem *= 10

        digit = rem / den

        rem %= den

        pos++

    if rem == 0 return 0 else return pos - seen[rem]

---
### Reference

    Project Euler Problem 26: https://projecteuler.net/problem=26

## License

Free to use for learning purposes.