#problem approach

Problem - "Largest Product in a Series"
Find the greatest product of n adjacent digits in the given 1000-digit number.

## Approach

The idea is to check every possible window of `n` consecutive digits in the 1000-digit number.

For each starting index:

1. Take the next `n` digits.
2. Multiply them together.
3. Compare the product with the current maximum.
4. Update the maximum if the new product is larger.

This is a simple sliding-window style approach.

---

## Why This Works

Every valid group of `n` consecutive digits appears exactly once in the scan.

So by checking all possible windows, we are guaranteed to find the largest product.

---

## Important Notes

- Use `long long` for the product, because the final answer can be larger than a 32-bit `int`.
- The inner loop must multiply digits from `i` to `i + n - 1`.
- The outer loop should run until the last valid starting position.

---

## Complexity

Let `n` be the number of adjacent digits required.

- Time complexity: `O(1000 * n)`
- Space complexity: `O(1)`

This is efficient enough for the given 1000-digit input.

---

## Example

If `n = 4`, then we check:

- digits `0..3`
- digits `1..4`
- digits `2..5`
- and so on

For each block, compute the product and keep the largest one.