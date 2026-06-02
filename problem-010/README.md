# Summation of Primes

## Problem Statement

Find the sum of all prime numbers up to a given limit `n`.

For example:

- Primes up to `10` are `2, 3, 5, 7`
- Their sum is `17`

For the classic Project Euler version, the limit is `2,000,000`.

---

## Approach

To solve this efficiently, we use the **Sieve of Eratosthenes**.

The sieve works by:

1. Creating a list of numbers from `2` to `n`.
2. Marking `0` and `1` as non-prime.
3. Starting from the first prime `2`, mark all of its multiples as non-prime.
4. Move to the next unmarked number and repeat.
5. Continue until `sqrt(n)`.

After the sieve finishes, all unmarked numbers are prime.

---

## Why This Works

If a number is composite, it has at least one factor less than or equal to its square root.

So, when marking multiples, it is enough to process only primes up to `sqrt(n)`.

This makes the sieve much faster than checking each number individually.

---

## Time Complexity

The Sieve of Eratosthenes runs in approximately:

`O(n log log n)`

This is why it is a standard solution for prime-related problems with large limits like `2,000,000`. 

---

## Space Complexity

The sieve stores a boolean array of size `n + 1`, so the space complexity is:

`O(n)`

---

## Notes

- `long long` is used for the sum because the total can become large.
- The sieve starts marking from `p * p` because smaller multiples were already marked by smaller primes.
- This solution is efficient enough for `n = 2,000,000`.

---

## Example

For `n = 20`:

Primes are:

`2, 3, 5, 7, 11, 13, 17, 19`

Sum:

`77`