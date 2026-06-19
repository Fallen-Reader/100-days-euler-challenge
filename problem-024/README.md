# Project Euler #24 — Lexicographic Permutations

A solution to [Project Euler Problem 24](https://projecteuler.net/problem=24), which asks for the millionth lexicographic permutation of the digits 0–9.

## Problem Statement

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3, and 4. If all permutations are listed numerically or alphabetically, we call it lexicographic order.

The lexicographic permutations of 0, 1, and 2 are:

```
012   021   102   120   201   210
```

**Task:** Find the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.

## Approach

### Brute Force (naive)

Generate every permutation in order and count up to the millionth. This works for 10 digits (3,628,800 permutations) but doesn't scale — for larger digit sets the number of permutations grows as *n!*, which becomes computationally infeasible.

### Optimal Approach — Factorial Number System

The key insight: with *n* distinct digits, there are *n!* total permutations. Fixing the first digit, the remaining *(n−1)* digits can be arranged in *(n−1)!* ways. This means permutations are grouped into predictable blocks:

- The first *(n−1)!* permutations start with the smallest remaining digit.
- The next *(n−1)!* start with the second smallest.
- And so on.

So instead of generating permutations, we can compute each digit directly by dividing the target rank by the appropriate factorial.

#### Algorithm

1. Convert the target rank to 0-indexed: `target = 1,000,000 - 1 = 999,999`
2. Start with the digit pool `[0,1,2,...,9]`
3. For each position, from most significant to least:
   - Compute `block = (remaining_count - 1)!`
   - `index = target / block` selects the next digit from the pool
   - Append `digits[index]` to the result and remove it from the pool
   - Update `target = target % block`
4. Repeat until the pool is empty

#### Complexity

| Approach | Time | Space |
|---|---|---|
| Brute force | O(n!) | O(n!) |
| Factorial number system | O(n²) | O(n) |

The O(n²) cost comes from removing an element from the digit list at each step. For n = 10 this is trivial, but the technique remains efficient for much larger n where brute force is impossible.


### Output

```
2783915460
```

## How It Works

Suppose we want the millionth permutation of `{0,1,...,9}` (target = 999999, 0-indexed):

| Step | Remaining digits | Block size `(n-1)!` | Index | Digit chosen | New target |
|---|---|---|---|---|---|
| 1 | `[0,1,2,3,4,5,6,7,8,9]` | 362880 | 2 | 2 | 274239 |
| 2 | `[0,1,3,4,5,6,7,8,9]` | 40320 | 6 | 7 | 32319 |
| 3 | `[0,1,3,4,5,6,8,9]` | 5040 | 6 | 8 | 2079 |
| ... | ... | ... | ... | ... | ... |

Each step narrows down one digit until the full permutation `2783915460` is assembled.

## License

MIT