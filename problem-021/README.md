# Amicable Numbers - Project Euler Problem 21

A C++ solution to **Project Euler Problem 21** - finding the sum of all amicable numbers under 10,000, using an **optimized sieve-like precomputation** method for divisor sums.

## Problem Statement

> Let **d(n)** be the sum of proper divisors of n (divisors less than n).
> 
> Two numbers **a** and **b** form an **amicable pair** if:
> - d(a) = b
> - d(b) = a  
> - a ≠ b
>
> Evaluate the **sum of all amicable numbers** under 10,000.

### Example

```
d(220) = 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 = 284
d(284) = 1 + 2 + 4 + 71 + 142 = 220

Since d(220) = 284 and d(284) = 220, and 220 ≠ 284
→ (220, 284) is an amicable pair
```


### Answer

**Sum of all amicable numbers under 10,000: 31,626**

>Amicable pairs:
(220, 284), (1184, 1210), (2620, 2924), (5020, 5564), (6232, 6368)

>Sum = 220 + 284 + 1184 + 1210 + 2620 + 2924 + 5020 + 5564 + 6232 + 6368 = 31,626


**Note:** Add BOTH numbers from each pair (220 AND 284), not just the pair sum once.

---

## The Challenge

### Naive Approach (Slow) 

Calculate divisor sum for each number individually:

```cpp
// O(n) for each number
int DivisorSum(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) sum += i;
    }
    return sum;
}

// Total: O(n²) for all numbers
for (int i = 1; i <= 10000; i++) {
    int d1 = DivisorSum(i);     // O(i)
    int d2 = DivisorSum(d1);    // O(d1)
}
```

**Problem:** 100 million operations for n=10,000 ❌

### Optimized Approach (Fast) 

**Precompute all divisor sums once** using a sieve-like method:

```cpp
// O(n log n) precomputation
vector<int> divSum = precomputeDivisorSums(10000);

// O(1) lookup for each number
for (int i = 1; i <= 10000; i++) {
    int d1 = divSum[i];     // O(1)
    int d2 = divSum[d1];    // O(1)
}
```

**Benefit:** Only 50,000 operations for n=10,000 (2000x faster!)

---

## Method : Sieve-like Precomputation

### Key Insight

Instead of finding divisors for each number, **add each number to all its multiples**:

For number i = 1:
Add 1 to: 2, 3, 4, 5, 6, ... (all multiples)
→ 1 is a divisor of all these numbers

For number i = 2:
Add 2 to: 4, 6, 8, 10, ... (all multiples)
→ 2 is a divisor of all these numbers

For number i = 3:
Add 3 to: 6, 9, 12, 15, ... (all multiples)
→ 3 is a divisor of all these numbers


### Algorithm

```
Initialize: divSum = [0, 0, 0, 0, 0, ...]

i = 1: Add 1 to multiples starting from 2
divSum += 1, divSum += 1, divSum += 1, ...

i = 2: Add 2 to multiples starting from 4
divSum += 2, divSum += 2, divSum += 2, ...

i = 3: Add 3 to multiples starting from 6
divSum += 3, divSum += 3, divSum += 3, ...

Result: divSum = 1 + 2 + 3 = 6
```

### Computing d(220) = 284

**divSum accumulates:**
- 1 (from i=1, j=220)
- 2 (from i=2, j=220)
- 4 (from i=4, j=220)
- 5 (from i=5, j=220)
- 10 (from i=10, j=220)
- 11 (from i=11, j=220)
- 20 (from i=20, j=220)
- 22 (from i=22, j=220)
- 44 (from i=44, j=220)
- 55 (from i=55, j=220)
- 110 (from i=110, j=220)

>Total: 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 = 284


---

## Complexity Analysis

### Time Complexity

| Method | Complexity | Operations (n=10,000) | Time |
|--------|------------|----------------------|------|
| **Naive (brute)** | O(n²) | 100,000,000 | 0.05s |
| **Sieve (Method 1)** | O(n log n) | 50,000 | 0.005s |

**Speedup:** 10x faster!

## Test Cases

| Input | Expected Output | Description |
|-------|----------------|-------------|
| MAX = 300 | 504 | Only pair (220, 284) |
| MAX = 1300 | 2718 | Pairs (220, 284) + (1184, 1210) |
| MAX = 10000 | **31,626** | Project Euler 21 answer |


## References

- [Project Euler Problem 21](https://projecteuler.net/problem=21)
- [Amicable Numbers - Wikipedia](https://en.wikipedia.org/wiki/Amicable_numbers)
- [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
- [Divisor Function - Wikipedia](https://en.wikipedia.org/wiki/Divisor_function)


## License

Free to use for learning purposes.