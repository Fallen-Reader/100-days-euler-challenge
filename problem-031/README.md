# Coin Sums - Project Euler Problem 31

A C++ solution to **Project Euler Problem 31** - finding the number of different ways to make £2 using any number of British coins, using **Dynamic Programming** (coin change algorithm).

## Problem Statement

> In England the currency is made up of eight coins:
> - 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
>
> It is possible to make £2 in the following way:
> ```
> 1 × £1 + 1 × 50p + 2 × 20p + 1 × 5p + 1 × 2p + 3 × 1p
> ```
>
> **How many different ways can £2 be made using any number of coins?**

### British Coins

| Coin | Value (pence) |
|------|---------------|
| 1p | 1 |
| 2p | 2 |
| 5p | 5 |
| 10p | 10 |
| 20p | 20 |
| 50p | 50 |
| £1 | 100 |
| £2 | 200 |

**Target:** 200p (₤2)

---

## The Challenge: Counting Combinations

### Why This is Hard

We need to count **all possible combinations**, not just one solution.

**For ₤2 (200p):** There are **73,682** different ways!

**Problem:** Exponential time complexity O(2^n) - too slow for large amounts!

## Dynamic Programming Approach

### Key Insight

**Think backwards:** Instead of finding all combinations, build up the answer.

> "How many ways can I make amount X?"
> 
> = "How many ways can I make amount (X - coin) for each coin?"

**Example: Ways to make 5p**

Using 1p: ways(5-1) = ways(4)

Using 2p: ways(5-2) = ways(3)

Using 5p: ways(5-5) = ways(0) = 1

Total = ways(4) + ways(3) + 1

### DP Table

Create an array `ways[]` where:
- `ways[i]` = number of ways to make amount `i`

**Base case:**
- `ways[0] = 1` (1 way to make 0: use no coins)

**Process:**
For each coin, update all amounts that can include this coin.

---

## Step-by-Step Explanation

### Algorithm Breakdown

```cpp
int No_of_ways(int amt, const vector<int>& coins) {
    vector<int> ways(amt + 1, 0);  // Create table
    ways = 1;                    // Base case
    
    for (int i = 0; i < coins.size(); i++) {  // For each coin
        for (int j = coins[i]; j < amt + 1; j++) {  // For each amount
            ways[j] += ways[j - coins[i]];  // Add ways using this coin
        }
    }
    
    return ways[amt];
}
```

### How It Works
```text
Initialize: ways = [1, 0, 0, 0, 0, 0, ...] (size 201)

Coin 1p:
j = 1: ways += ways[1-1] = ways = 1 → ways = 1
j = 2: ways += ways[2-1] = ways = 1 → ways = 1
j = 3: ways += ways[3-1] = ways = 1 → ways = 1
...
After coin 1: ways = [1, 1, 1, 1, 1, 1, ...]
(Only 1 way to make any amount using just 1p coins)

Coin 2p:
j = 2: ways += ways[2-2] = ways = 1 → ways = 1+1 = 2
(2 ways: 2×1p or 1×2p)
j = 3: ways += ways[3-2] = ways = 1 → ways = 1+1 = 2
(2 ways: 3×1p or 1×2p+1×1p)
j = 4: ways += ways[4-2] = ways = 2 → ways = 1+2 = 3
(3 ways: 4×1p, 2×2p, 1×2p+2×1p)
...
After coin 2: ways = [1, 1, 2, 2, 3, 3, 4, 4, ...]

Coin 5p:
j = 5: ways += ways[5-5] = ways = 1 → ways = 3+1 = 4
(4 ways using 1p, 2p, and 5p)
j = 6: ways += ways[6-5] = ways = 1 → ways = 3+1 = 4
j = 7: ways += ways[7-5] = ways = 2 → ways = 3+2 = 5
...
After coin 5: ways = 10 (10 ways to make 10p)

Continue for coins 10p, 20p, 50p, £1, £2...

Final: ways = 73,682
```

Coins:, Target: 5p

Initialize: ways =

After Coin 1p:
ways =
(1 way each: all 1p coins)

After Coin 2p:

    ways += ways = 1 → ways = 2
    ways += ways = 1 → ways = 2
    ways += ways = 2 → ways = 3
    ways += ways = 2 → ways = 3


After Coin 5p:

    ways += ways = 1 → ways = 3+1 = 4

**Result**: 4 ways to make 5p

Ways:

    5 × 1p

    3 × 1p + 1 × 2p

    1 × 1p + 2 × 2p

    1 × 5p

---

## Why This Works

### Key Concept: Order Doesn't Matter

We count **combinations**, not permutations:


**How the algorithm avoids double-counting:**

```cpp
for (int i = 0; i < coins.size(); i++) {  // Process coins in order
    for (int j = coins[i]; j < amt + 1; j++) {
        ways[j] += ways[j - coins[i]];
    }
}
```

**Outer loop processes coins in order:**
- First use only 1p coins
- Then use 1p + 2p coins
- Then use 1p + 2p + 5p coins
- ...

**This ensures:** Each combination is counted exactly once (coins in sorted order).

---

## Complexity Analysis

### Time Complexity

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| Outer loop | O(coins) | 8 coins |
| Inner loop | O(amt) | 200 amounts |
| **Total** | **O(amt × coins)** | 200 × 8 = 1,600 operations |

**Operations:**

**Runtime:** ~0.0001 seconds (extremely fast!)

### Space Complexity

- **O(amt)** for the `ways[]` array
- **Array size:** 201 integers = 804 bytes

---

## References

- [Project Euler Problem 31](https://projecteuler.net/problem=31)
- [Coin Change Problem - Wikipedia](https://en.wikipedia.org/wiki/Coin_change_problem)
- [Dynamic Programming](https://en.wikipedia.org/wiki/Dynamic_programming)
- [Combinatorics](https://en.wikipedia.org/wiki/Combinatorics)

## Summary

| Metric | Value |
|--------|-------|
| **Algorithm** | Dynamic Programming |
| **Time Complexity** | O(amt × coins) = 1,600 operations |
| **Space Complexity** | O(amt) = 201 integers |
| **Runtime** | ~0.0001 seconds |
| **Answer** | **73,682** ways to make £2 |

**Key Insight:** Build up from small amounts using each coin once.

**Answer:** 73,682 

---

## License

Free to use for learning purposes.