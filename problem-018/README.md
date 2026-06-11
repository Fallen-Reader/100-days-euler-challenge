# Maximum Path Sum I - Project Euler Problem 18

A C++ solution to **Project Euler Problem 18** - finding the maximum path sum from top to bottom of a triangle, where you can only move to adjacent numbers on the row below.

## Problem Statement

> Starting from the top of the triangle, move to adjacent numbers on the row below to find the maximum total from top to bottom.
>
> ```
>     3
>    7 4
>   2 4 6
>  8 5 9 3
> ```
>
> The maximum path is: **3 → 7 → 4 → 9 = 23**

**Rules:**
- From position `(i, j)`, you can move to `(i+1, j)` or `(i+1, j+1)`
- Find the path with the maximum sum from top to bottom

## Why Greedy Approach Fails

A common mistake is to **greedily pick the larger number** at each step:

```cpp
// ❌ WRONG: Greedy approach
if (next_left > next_right) {
    pick next_left;
} else {
    pick next_right;
}
```

**Problem**: This ignores future numbers. A smaller number now might lead to much larger numbers later!

| Approach | Works? | Why? |
|----------|--------|------|
| Greedy (pick larger now) | ❌ No | Doesn't consider entire path |
| Dynamic Programming | ✅ Yes | Considers all possible paths |

## Solution: Dynamic Programming (Bottom-Up)

### Key Insight

> For each position, calculate the **maximum path sum from that position to the bottom**.

Work **bottom-up**: the top element will eventually contain the maximum path sum.

### Algorithm
For each position (i, j):
```
counter[i][j] = triangle[i][j] + max(counter[i+1][j], counter[i+1][j+1])
```
Start from bottom row, move up to top.

```
Initial triangle:
        3
       7 4
      2 4 6
     8 5 9 3

After processing row 2 (i=2):
        3
       7 4
    10 13 15    ← 2+max(8,5)=10, 4+max(5,9)=13, 6+max(9,3)=15

After processing row 1 (i=1):
       3
     20  18       ← 7+max(10,13)=20, 4+max(13,15)=18

After processing row 0 (i=0):
      23           ← 3+max(20,18)=23

Answer: 23
```

## Complexity Analysis

| Metric | Value |
|--------|-------|
| **Time** | O(n²) where n = number of rows |
| **Space** | O(n²) for DP table (can be optimized to O(n)) |
| **Operations** | Visit each element once |

For a triangle with 15 rows (Problem 18): 15² = 225 operations

## Why DP Works

1. **No Regret**: Once we compute `counter[i][j]`, we know it's the optimal path from that point
2. **Memoization**: We store results instead of recalculating
3. **Bottom-Up**: Starting from bottom ensures we have all future values ready

## Related Problems

- [Project Euler Problem 67](https://projecteuler.net/problem=67) - Maximum path sum II (larger triangle)

## References

- [Project Euler Problem 18](https://projecteuler.net/problem=18)
- [Dynamic Programming Explained](https://www.geeksforgeeks.org/dynamic-programming/)
- [Triangle DP Problem - LeetCode](https://leetcode.com/problems/triangle/)

## License

Free to use for learning purposes.