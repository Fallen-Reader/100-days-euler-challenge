# Factorial Digit Sum - Optimized (Base 10000)

A C++ solution to **Project Euler Problem 20** - finding the sum of digits in 100 factorial (100!), using an **optimized base-10000 representation** for large number arithmetic.

## Problem Statement

> **n!** means n × (n − 1) × ... × 3 × 2 × 1
> 
> Find the sum of the digits in **100!**

**Example:**
- 10! = 10 × 9 × ... × 2 × 1 = 3,628,800
- Sum of digits in 10! = 3 + 6 + 2 + 8 + 8 + 0 + 0 = **27**

## The Challenge

100! is an **enormous number** with 158 digits:

`100! = 93,326,215,443,944,152,681,699,238,856,266,700,490,349,
644,493,668,599,680,200,000,000,000,000`


**Standard integer types cannot store this!**
- `int`: max 2,147,483,647 (10 digits)
- `long long`: max 9,223,372,036,854,775,807 (19 digits)
- 100!: 158 digits ❌

## Solution: Big Integer with Base 10000

### Why Not Base 10?

**Naive approach** (store each decimal digit separately):

```cpp
vector<int> digits = {1};

for (int i = 0; i < digits.size(); i++) {
    int val = digits[i] * j + carry;
    digits[i] = val % 10;   
    carry = val / 10;
}
```

**Problems:**
- 158 iterations for 100!
- Modulo/division is slow
- Memory inefficient

### Optimized: Base 10000

Store **4 decimal digits** in each array element:

```cpp
vector<int> digits = {1}; 
const int BASE = 10000;

for (int i = 0; i < digits.size(); i++) {
    long long val = digits[i] * j + carry;
    digits[i] = val % BASE;  // Store 4 digits
    carry = val / BASE;
}
```

**Benefits:**
- ✅ Only 39 iterations (158 ÷ 4) instead of 158
- ✅ 4x faster multiplication
- ✅ 4x less memory


## Step-by-Step Example (5!)

```text
Start: digits = (represents 1 in base 10000)

Multiply by 2:
val = 1 × 2 + 0 = 2
digits = 2 % 10000 = 2
carry = 2 / 10000 = 0
digits = (represents 2)

Multiply by 3:
val = 2 × 3 + 0 = 6
digits = 6
carry = 0
digits = (represents 6)

Multiply by 4:
val = 6 × 4 + 0 = 24
digits = 24
carry = 0
digits = (represents 24, which is 24 in decimal)

Multiply by 5:
val = 24 × 5 + 0 = 120
digits = 120
carry = 0
digits = (represents 120)

Sum decimal digits:
120 → 1 + 2 + 0 = 3 ✅ (5! = 120)
```

## Complexity Analysis

| Metric | Base 10 | Base 10000 | Improvement |
|--------|---------|------------|-------------|
| **Time** | O(n × d) | O(n × d/4) | 4x faster |
| **Space** | O(d) | O(d/4) | 4x less |
| **Iterations for 100!** | 158 | 39 | 4x fewer |
| **Iterations for 1000!** | 2,568 | 642 | 4x fewer |

Where `d` = number of decimal digits in n!

## Why Base 10000?

| Base | Digits per Element | Iterations (100!) | Pros | Cons |
|------|-------------------|-------------------|------|------|
| 10 | 1 | 158 | Simple | Slow |
| **100** | 2 | 79 | Faster | Still many modulos |
| **10000** | 4 | 39 | ✅ Best balance | Moderate complexity |
| **10¹⁶** | 16 | 10 | Extremely fast | Needs 128-bit math |

**Base 10000** is the sweet spot:
- ✅ 4x speedup
- ✅ Fits in `int` (no overflow for n ≤ 1000)
- ✅ Simple modulo/division


## Test Cases

| Input | Expected Output | Description |
|-------|----------------|-------------|
| `sumOfDigits(1)` | 1 | 1! = 1 |
| `sumOfDigits(5)` | 3 | 5! = 120 |
| `sumOfDigits(10)` | 27 | 10! = 3,628,800 |
| `sumOfDigits(100)` | **648** | Project Euler 20 answer |
| `sumOfDigits(1000)` | 10,545 | 1000! (1000 digits) |

## Files

| File | Description |
|------|-------------|
| `SumOfDigits.cpp` | Main implementation with base-10000 optimization |
| `README.md` | This documentation |

## Learning Concepts

This project demonstrates:
- **Big integer arithmetic** without external libraries
- **Base representation** optimization (base 10000 vs base 10)
- **Carry propagation** in multiplication
- **Modulo arithmetic** for digit extraction
- **Memory efficiency** via block storage

## Related Problems

| Problem | Link | Similarity |
|---------|------|------------|
| Project Euler 16 | [Power digit sum](https://projecteuler.net/problem=16) | Same big number concept |
| Project Euler 20 | [Factorial digit sum](https://projecteuler.net/problem=20) | This problem |
| Project Euler 429 | [Sum of squares of digits](https://projecteuler.net/problem=429) | Digit manipulation |
| LeetCode 66 | [Plus One](https://leetcode.com/problems/plus-one/) | Big integer addition |

## References

- [Project Euler Problem 20](https://projecteuler.net/problem=20)
- [Big Integer Arithmetic](https://en.wikipedia.org/wiki/Arithmetic_on_p-moving_parts)
- [Modular Arithmetic](https://en.wikipedia.org/wiki/Modular_arithmetic)
- [GMP Library](https://gmplib.org/) - Alternative: use existing big int library


## License

Free to use for learning purposes.