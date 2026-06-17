# Name Scores - Project Euler Problem 22

A C++ solution to **Project Euler Problem 22** - calculating the total of all name scores from a file of over 5,000 first names.

## Problem Statement

> Using [names.txt](https://projecteuler.net/project/resources/p0022_names.txt), a 46K text file containing over five-thousand first names, **start by sorting it into alphabetical order**. Then working out the **alphabetical value** for each name, multiply this value by its **alphanumeric position** in the list to find the name score.
>
> For example, once the list is sorted, **PAIGE** is the 93rd name. The alphabetical value of PAIGE is 16+1+9+7+5 = **38**. So PAIGE has a name score of **93 × 38 = 3,534**.
>
> **What is the total of all the name scores in the file?**

### How to Calculate Name Score

**Step 1: Alphabetical Value**
- A = 1, B = 2, C = 3, ..., Z = 26
- Sum the values of all letters in the name

**Example:** PAIGE

- P = 16
- A = 1
- I = 9
- G = 7
- E = 5
- Alphabetical value = 16 + 1 + 9 + 7 + 5 = 38

---

**Step 2: Name Score**
>Name Score = Position × Alphabetical Value
- PAIGE's score = 93 × 38 = 3,534


---

## Algorithm Overview

1. Read names from file (0022_names.txt)

2. Remove quotation marks from each name

3. Split comma-separated names into individual strings

4. Sort names alphabetically

5. For each name:

        Calculate alphabetical value (A=1, B=2, ..., Z=26)

        Multiply by position (1st, 2nd, 3rd, ...)

        Add to total

6. Output total


---

## Code Explanation

### Function 1: `getNameValue()` - Calculate Alphabetical Value

```cpp
long long getNameValue(const string& name) {
    long long value = 0;
    for (char c : name) {
        if (c >= 'A' && c <= 'Z') {
            value += (c - 'A' + 1); 
        }
    }
    return value;
}
```

**How it works:**
- Iterate through each character in the name
- If character is uppercase letter (A-Z):
  - `c - 'A'` gives 0 for A, 1 for B, ..., 25 for Z
  - Add 1 to get 1 for A, 2 for B, ..., 26 for Z
- Sum all values


---

### Function 2: `remove_quotes()` - Clean Quotation Marks

```cpp
string remove_quotes(string& s) {
    s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    return s;
}
```

**How it works:**
- `remove(s.begin(), s.end(), '\"')` moves all `"` characters to the end
- `s.erase(...)` removes them from the string
- Returns cleaned string

**Example:**
```
Input: "MARIA"
Output: MARIA
```


---

### Main Function - Complete Workflow

```cpp
int main(){
    // STEP 1: Open file
    ifstream file("0022_names.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }
```

**Opens the names file** containing: `"MARY","PATRICIA","LINDA",...`

```cpp
    // STEP 2: Read entire file content
    string line;
    vector<string> names;
    
    while(getline(file,line)){
        string cleaned = remove_quotes(line);
        names.push_back(cleaned);
    }
    file.close();
```

**Reads all lines** into a vector (for this file, it's all on one line).

```cpp
    // STEP 3: Split comma-separated names
    stringstream idk(names);
    names.clear();
    
    while(getline(idk,line,',')){
        names.push_back(line);
    }
```

**Splits by comma** to get individual names:
```
Input: "MARY","PATRICIA","LINDA"
Output: ["MARY", "PATRICIA", "LINDA"]
```


**Note:** Variable name `idk` is a `nameStream`.

```cpp
    // STEP 4: Sort alphabetically
    sort(names.begin(), names.end());
```


```cpp
    // STEP 5: Calculate total score
    long long total = 0;
    for (size_t i = 0; i < names.size(); ++i) {
        int value = getNameValue(names[i]);
        long long position = i + 1;
        total += position * value;
    }
    
    cout << "Total of all name scores: " << total << "\n";
    return 0;
}
```


---

## Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n log n + n × m) | Sorting: O(n log n), Scoring: O(n × m) |
| **Space** | O(n × m) | Store n names, each with average length m |

Where:
- n = number of names (5,163)
- m = average name length (~6 characters)

### Operations Count
```
Reading file: 5,163 lines
Splitting: 5,163 names
Sorting: 5,163 × log(5,163) ≈ 62,000 comparisons
Calculating: 5,163 × 6 chars ≈ 31,000 operations
Total: ≈ 100,000 operations (runs in < 0.01s)
```
---

## Learning Concepts

This project demonstrates:
- **File I/O** with `ifstream`
- **String manipulation** (removing characters)
- **String splitting** with `stringstream`
- **Sorting** strings alphabetically
- **Character arithmetic** (A:1, B:2, ...)
- **Vector operations** (push_back, sort)
- **Long long** for large numbers (avoid overflow)

---

## License

Free to use for learning purposes.