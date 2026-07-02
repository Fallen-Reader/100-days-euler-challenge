# Project Euler 33 — Digit Cancelling Fractions

## The Problem

The fraction `49/98` is a curious fraction, as an inexperienced mathematician
attempting to simplify it might incorrectly believe that:

```
49/98 = 4/8
```

...by cancelling the shared digit `9`. This "cancellation" happens to give the
*correct* simplified value, even though it's mathematically invalid in
general.

We're interested in fractions like this where:

- The numerator and denominator are both **two-digit numbers** (10–99).
- The fraction is **less than 1** (numerator < denominator).
- The two numbers share **exactly one common digit**, which appears in the
  numerator and somewhere in the denominator.
- After "cancelling" that shared digit, the resulting fraction is equal in
  value to the original fraction.
- The fraction is **non-trivial** — we exclude the trivial cases where both
  digits happen to be the same and the denominator ends in the same digit as
  it starts (e.g. `11/11`, `22/22`, ..., `99/99`), since cancelling a zero
  digit or matching identical digits like these doesn't represent a genuine
  curiosity.

There are exactly **four** non-trivial examples of this for two-digit
fractions:

```
16/64 = 1/4
19/95 = 1/5
26/65 = 2/5
49/98 = 4/8
```

**Goal:** If you multiply these four fractions together, and express the
result in lowest terms, find the value of the **denominator**.

## Approach

### Step 1 — Represent each fraction by its digits

For a numerator `j` and denominator `i` (both two-digit numbers), write:

- `n` = tens digit of `j`, `c1` = units digit of `j`
- `c2` = tens digit of `i`, `d` = units digit of `i`

So `j = 10*n + c1` and `i = 10*c2 + d`.

### Step 2 — Search all valid two-digit pairs

Loop `i` from 12 to 99, and `j` from 11 up to `i - 1` (ensuring the fraction
`j/i` is proper, i.e. less than 1).

**Skip trivial cases:** if either digit is `0`, cancelling it isn't a genuine
"shared digit" cancellation (it just removes a trailing zero), so skip these
with `continue`.

### Step 3 — Find the shared digit

The "cancelling" only makes sense if the units digit of the numerator matches
the tens digit of the denominator (`c1 == c2`). This is the digit that gets
struck out. Also require `n < d`, since we want the *reduced* fraction (after
cancelling) to have a smaller numerator than denominator, keeping the
comparison consistent as digits rather than by coincidence.

### Step 4 — Check the cancellation is valid

Compute both:

- The original fraction: `frac_original = j / i`
- The "cancelled" fraction: `frac_cancelled = n / d`

If these are equal, we've found a genuine curious fraction. Collect it.

### Step 5 — Multiply the four fractions and reduce

Once all four fractions are found:

```
prod_numerator   = product of all four numerators (j values)
prod_denominator = product of all four denominators (i values)
```

Reduce `prod_numerator / prod_denominator` to lowest terms by dividing both
by their **GCD** (greatest common divisor), computed via the Euclidean
algorithm:

```
gcd(a, b) = a               if b == 0
gcd(a, b) = gcd(b, a mod b) otherwise
```

The denominator of this fully reduced fraction is the answer.

## Common Pitfalls (and fixes)

1. **Using `break` instead of `continue`** when skipping digits ending in
   zero. Since `j` increases across the inner loop, a `j` divisible by 10 can
   occur *before* the target `j` for a given `i`. Using `break` abandons the
   rest of the inner loop and silently skips valid answers (e.g. `26/65`).

2. **Reconstructing `i` incorrectly.** If you split `i` into `c2` (tens) and
   `d` (units), remember `i = 10*c2 + d`. Rebuilding it as `10*d + c2` swaps
   the digits and produces the wrong number entirely. Simplest fix: just use
   `i` and `j` directly rather than reconstructing them from digits.

3. **Mixing up numerator/denominator accumulators.** When accumulating the
   product, make sure the variable meant to hold the numerator product is
   actually multiplied by numerators (`j`), and the denominator accumulator
   is multiplied by denominators (`i`) — not swapped.

4. **Using `double` for GCD/product logic.** Floating-point works here only
   because the numbers involved happen to stay small and exact, but it's
   fragile. Prefer `int` or `long long` for all product and GCD computations,
   reserving `double` only for the equality check between fractions (or, even
   better, cross-multiply to avoid floating-point comparison entirely:
   `j * d == n * i`).

## Result

Multiplying the four fractions:

```
(16/64) × (19/95) × (26/65) × (49/98)
```

and reducing to lowest terms gives a denominator of **100**.