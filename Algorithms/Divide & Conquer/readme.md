# Divide & Conquer — Problem Solving Guide

Divide & Conquer (D&C) is a fundamental algorithmic paradigm where a problem is:
1. **Divided** into smaller independent subproblems  
2. **Solved recursively**  
3. **Combined** to produce the final result  

This repository provides a **general thinking framework**, **common patterns**, and **mental checklists** to approach any Divide & Conquer problem confidently.

---

## 🔑 Core Principle

> **Fix the last decision (or split point), solve the rest recursively.**

Most D&C problems follow this structure:
```

solve(left subproblem)
solve(right subproblem)
combine(left, right)

```

---

##  Universal Step-by-Step Approach

### 1️ Identify if Divide & Conquer Applies
Ask:
- Can the problem be broken into **independent subproblems**?
- Can the final answer be **combined** from sub-answers?

Common keywords:
- range `[l..r]`
- maximum / minimum
- all possible ways
- expression evaluation
- binary tree / recursion

---

### 2️ Identify the Split Point (MOST IMPORTANT)
The split point defines the recursion.

| Problem Type | Typical Split |
|-------------|---------------|
| Array | Middle index |
| Expression | Operator position |
| Tree | Root node |
| Range | Mid point |
| Decisions | Last operation |

Examples:
- Merge Sort → middle index
- Maximum Subarray → middle index
- Majority Element → middle index
- Parenthesization → operator
- Matrix Chain Multiplication → last multiplication

---

### 3️ Define the Subproblem Clearly
Always define **what one recursive call solves**.

Examples:
```

solve(l, r) → answer for subarray [l..r]
solve(expr) → all possible results of expression
solve(node) → answer for subtree rooted at node

```

If the subproblem is unclear, the solution will be unclear.

---

### 4️ Write the Base Case First
Base cases represent the **smallest solvable unit**.

Examples:
- One element
- One number
- Leaf node

⚠️ Most bugs in D&C come from incorrect or missing base cases.

---

### 5️ Combine the Results (Common Patterns)

#### 🔹 Pattern A: Choose Best
Used when the answer is a max/min.
```

return max(left, right, cross);

```
Examples:
- Maximum Subarray
- Closest Pair of Points

---

#### 🔹 Pattern B: Agreement Check
Used when both halves may agree.
```

if (left == right) return left;
else decide using frequency / rule

```
Examples:
- Majority Element

---

#### 🔹 Pattern C: Cartesian Product
Used when **all combinations** are required.
```

for each l in left:
for each r in right:
combine(l, r)

```
Examples:
- Different Ways to Add Parentheses
- Boolean Parenthesization

---

#### 🔹 Pattern D: Merge
Used when subproblems produce sorted/structured results.
```

merge(leftResult, rightResult)

```
Examples:
- Merge Sort
- Count Inversions

---

### 6️ Optimize Using Memoization (If Needed)
If the same subproblem is solved repeatedly:
- Use `dp[l][r]` for index-based problems
- Use `map<string, result>` for expression problems

This converts pure D&C into **Top-Down Dynamic Programming**.

---

## 🏆 Golden Rule

> **If you can fix the last step, recursion will solve the rest.**

Once this mindset clicks, Divide & Conquer becomes mechanical and predictable.

---