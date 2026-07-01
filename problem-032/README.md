# Project Euler – Problem 32

**Pandigital Products**

> We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.  
> Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

**Answer: 45228**

---

## The Problem

We want to find every identity of the form:

```
a × b = c
```

where the digits of `a`, `b`, and `c` together use each of the digits **1–9 exactly once** — no repeats, no omissions. Then sum all the unique values of `c`.

For example:

```
39 × 186 = 7254     → digits used: 3,9,1,8,6,7,2,5,4  ✓
4 × 1738 = 6952     → digits used: 4,1,7,3,8,6,9,5,2  ✓
```

---

## Approach: Permutation Search

Since there are exactly 9 digits (1–9) and each must appear exactly once across the entire identity, we can frame this as a search over all permutations of `[1, 2, 3, 4, 5, 6, 7, 8, 9]`.

For each permutation, we slice the 9-digit sequence into three parts of lengths `lenA`, `lenB`, and `lenC = 9 - lenA - lenB`, interpret each part as an integer, and check whether `a × b == c`.

```
Permutation:  [ 3, 9, 1, 8, 6, 7, 2, 5, 4 ]
               |--a--|--b--------|---c----|
                 39  ×   186    =   7254   ✓
```

A `std::set<int>` collects valid products — the set ensures each product is counted only once even if it arises from multiple (a, b) pairs.

---

## Why `n = 9` is Fixed

The digits 1–9 are exactly 9 digits. The identity `a × b = c` must together use all 9. There's no user input — the problem is defined over this fixed set.

A useful constraint on valid splits comes from how multiplication affects digit counts. If `a` has `m` digits and `b` has `n` digits, then `a × b` has at most `m + n` digits. For the total to be exactly 9:

```
lenA + lenB + lenC = 9
lenC ≈ lenA + lenB  (product digit count)
```

This means only two splits are realistically productive:

| lenA | lenB | lenC |
|------|------|------|
| 1    | 4    | 4    |
| 2    | 3    | 4    |

The code still tries all splits — the permutation approach naturally discards invalid ones since `a * b == c` won't hold — but this insight explains why 45228 is the answer and not something much larger.

---

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    const int n = 9;
    vector<int> digits(n);
    set<int> products;

    for (int i = 0; i < n; i++) digits[i] = i + 1;

    do {
        for (unsigned lenA = 1; lenA < n; lenA++) {
            for (unsigned lenB = 1; lenB < n - lenA; lenB++) {
                unsigned lenC = n - lenA - lenB;

                unsigned pos = 0;
                unsigned a = 0;
                for (unsigned i = 0; i < lenA; i++) { a = a * 10 + digits[pos++]; }

                unsigned b = 0;
                for (unsigned i = 0; i < lenB; i++) { b = b * 10 + digits[pos++]; }

                unsigned c = 0;
                for (unsigned i = 0; i < lenC; i++) { c = c * 10 + digits[pos++]; }

                if (a * b == c) {
                    products.insert(c);
                }
            }
        }
    } while (next_permutation(digits.begin(), digits.end()));

    unsigned long long sum = 0;
    for (auto num : products) sum += num;
    cout << "Sum of all pandigital products: " << sum << endl;
}
```

---



## Complexity

| | |
|---|---|
| Total permutations of [1–9] | 9! = 362,880 |
| Splits checked per permutation | ~28 (lenA × lenB combinations) |
| Operations per split | O(9) digit reads + 1 multiply |
| Total | ~10M simple operations |

Runs in well under a second.

---

## Common Pitfalls

**Wrong loop variable for `b` and `c`** — the most natural bug is writing all three digit-reading loops with the same length variable. `a` reads `lenA` digits, `b` reads `lenB`, and `c` reads `lenC`. Using `lenA` throughout causes `b` and `c` to read the wrong number of digits and sends `pos` out of bounds for most splits.



**Not using a set for products** — the same product value (e.g. 7254) can arise from more than one valid (a, b) pair. Summing raw results double-counts these; a `std::set` deduplicates automatically.

---

## Related Problems

- [Problem 24](https://projecteuler.net/problem=24) — lexicographic permutations (same `next_permutation` technique)
- [Problem 38](https://projecteuler.net/problem=38) — pandigital multiples
- [Problem 41](https://projecteuler.net/problem=41) — pandigital primes