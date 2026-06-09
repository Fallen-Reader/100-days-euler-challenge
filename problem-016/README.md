# Power Digit Sum – Sum of Digits of $$2^{exponent}$$

## Problem

Given an integer `exponent`, compute:

1. The value of $$2^{exponent}$$(which can be extremely large for big exponents).
2. The **sum of the decimal digits** of that value.

Example:

- \(2^{15} = 32768\)
- Digit sum = \(3 + 2 + 7 + 6 + 8 = 26\).

For large exponents (like 1000), $$2^{exponent}$$ no longer fits in standard integer types, so we cannot just compute the power and then sum the digits directly.

---

## Key Idea

Instead of storing $$2^{exponent}$$ in a built-in type (`int`, `long long`, etc.), store the number as a list of **decimal digits**, and simulate multiplication by 2 using the same method you use on paper:

- Keep an array / vector `digits`.
- Each element is a single digit (0–9).
- Repeatedly multiply the entire number by 2, digit by digit, handling carries.
- After repeating this `exponent` times, the vector represents $$2^{exponent}$$
- Finally, sum all digits in the vector.

This is a minimal “big integer” implementation specialized for powers of 2.

---

## How the representation works

We use:

```cpp
vector<int> digits = {1};
```

- The number is stored **least significant digit first**:
  - `digits[0]` = ones place
  - `digits[1]` = tens place
  - `digits[2]` = hundreds place
  - etc.
- Initially, the number is \(1 = 2^0\), so `digits = {1}`.

Each iteration of the outer loop multiplies the entire number by 2. After `exponent` iterations, the number becomes $$2^{exponent}$$

---

## Line-by-line explanation of the algorithm

```cpp
int digitSumOfPowerOfTwo(int exponent) {
    vector<int> digits = {1};
```

- Start with `digits` representing 1 (i.e., \(2^0\)).
- The goal is to repeatedly double this number.

```cpp
    for (int i = 0; i < exponent; i++) {
        int carry = 0;
```

- Repeat the doubling process `exponent` times.
- Before processing digits, set `carry = 0`. This will hold the carry value from each digit multiplication, just like in manual multiplication.

```cpp
        for (int j = 0; j < digits.size(); j++) {
            int value = digits[j] * 2 + carry;
            digits[j] = value % 10;
            carry = value / 10;
        }
```

- Loop over each digit from least significant to most significant.
- `value` is the result of doubling the current digit and adding the carry.
- `digits[j] = value % 10` keeps only the last digit of `value`.
- `carry = value / 10` keeps the rest (e.g., if `value = 15`, digit becomes 5, carry becomes 1).
- This simulates the hand-written process of multiplying a multi-digit number by 2.

```cpp
        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
```

- After processing all existing digits, there may still be leftover carry (e.g., doubling 999 gives 1998, so extra digit appears).
- While carry is nonzero:
  - Push the last digit of carry into `digits`.
  - Remove that digit from carry by dividing by 10.
- This grows the number of digits when $$2^{exponent}$$ gets more decimal digits.

- At this point, after the outer loop finishes, `digits` holds all digits of $$2^{exponent}$$, still least-significant-first.

```cpp
    int sum = 0;
    for (int d : digits) sum += d;
    return sum;
}
```

- Initialize `sum` to 0.
- Add each digit in the vector to `sum`.
- Return the final sum of digits.

---

## Why not use `pow(2, exponent)`?

Using `pow` or `std::pow` returns floating-point values and cannot represent huge integers like $$2^{1000}$$ exactly. Even with integer types, the value overflows very quickly.

By manually tracking digits:

- We avoid overflow.
- We can compute the exact decimal representation and its digit sum.
- This method works for large exponents such as 1000 (as in Project Euler 16).

---

## Example: small exponent

For `exponent = 5`:

- Start: 1
- After 1st doubling: 2
- After 2nd doubling: 4
- After 3rd doubling: 8
- After 4th doubling: 16 (`digits = [6, 1]`)
- After 5th doubling: 32 (`digits = [2, 3]`)

Sum of digits = `3 + 2 = 5`.

---

## Usage

```cpp
int main() {
    int exponent = 1000;
    int result = digitSumOfPowerOfTwo(exponent);
    cout << "Digit sum of 2^" << exponent << " = " << result << endl;
}
```

This will print the sum of the digits of $$2^{1000}$$ when using the algorithm above.