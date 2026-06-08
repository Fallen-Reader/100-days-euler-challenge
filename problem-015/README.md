# Project Euler 15 – Lattice Paths (Why Combinations?)

## Problem statement

Starting in the top-left corner of an `N × N` grid, you can only move **right** or **down**.  
How many different shortest paths are there to the bottom-right corner?

Example for a `2 × 2` grid: there are exactly 6 such paths.

This project computes that number for a given grid size using **combinatorics** instead of brute force.

---

## Why combinations appear here

### 1. Any shortest path has the same moves

To go from the **top-left** to the **bottom-right** corner of an `N × N` grid:

- You must move **right** exactly `N` times (to cross N columns).
- You must move **down** exactly `N` times (to cross N rows). 

You are not allowed to move up or left, and you want the shortest path, so you cannot take extra detours.

That means:

- Every shortest path is a sequence of `2N` moves.
- Among those `2N` moves:
  - exactly `N` are `R` (right),
  - exactly `N` are `D` (down).

So the problem becomes:

> In a sequence of length `2N` containing `N` `R`s and `N` `D`s, how many distinct sequences are there?

This is **exactly** a combinations / binomial coefficient question.

---

### 2. Rephrasing as a pure combinatorics problem

Think of writing a string of length `2N`, where you place `R` and `D`.

- You need to choose **which positions** (indices) in that string will be `R`.
- Once the positions of the `R`s are fixed, the `D`s are automatically fixed (they go in all the remaining positions).

So the question reduces to:

> How many ways to choose `N` positions out of `2N`?

This is exactly the definition of the binomial coefficient:

\[
\binom{2N}{N}
\]

which means “2N choose N”.

Equivalently, you could choose where the `D`s go, but that gives the same count:

\[
\binom{2N}{N} = \binom{2N}{2N - N}
\]

---

### 3. The formula for combinations

The binomial coefficient \(\binom{n}{k}\) counts the number of ways to choose `k` items from `n` items, ignoring order, and has the formula:

\[
\binom{n}{k} = \frac{n!}{k! (n-k)!}
\]

In our lattice path problem:

- \(n = 2N\) (total moves),
- \(k = N\) (number of right moves, or down moves),

so:

\[
\text{number of paths} = \binom{2N}{N}
= \frac{(2N)!}{N! N!}
\]

This directly gives the count of all shortest paths on the grid.

---

### 4. Why this is better than brute force

A brute force approach would:

- try to generate all possible paths,
- filter only those that end at the bottom-right,
- count them.

This explodes combinatorially as `N` grows.

Using the combination formula:

- you avoid generating any paths,
- you compute a single exact number using arithmetic,
- you can solve cases like `20 × 20` instantly.

---

## Implementation idea (without large factorial overflow)

Directly using factorials can overflow even 64-bit integers when computing `(2N)!`, so a safer method uses a multiplicative formula for the binomial coefficient:

\[
\binom{2N}{N} = \prod_{i=1}^{N} \frac{2N + 1 - i}{i}
\]

In C++:

```cpp
long long lattice_path(int gridSize) {
    long long total_paths = 1;
    int total_steps = 2 * gridSize;
    int right_moves = gridSize;

    for (int i = 1; i <= right_moves; i++) {
        total_paths = total_paths * (total_steps + 1 - i) / i;
    }
    return total_paths;
}
```

This computes \(\binom{2N}{N}\) directly and safely for `N = 20` (the classic Project Euler case).

---

## Summary: where combination really comes from

1. Every shortest path is exactly `N` rights and `N` downs.
2. A path is just an ordering of those moves.
3. Counting paths = counting distinct orderings of `N` `R`s and `N` `D`s in a length `2N` sequence.
4. That is “2N choose N” = \(\binom{2N}{N}\).

So combinations are not just a trick; they are a direct translation of the structure of the paths into a counting problem.