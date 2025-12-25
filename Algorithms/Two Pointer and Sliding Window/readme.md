#  Two Pointers & Sliding Window

These patterns are essential for solving **array** and **string** problems efficiently, especially when dealing with **subarrays**, **substrings**, and **ranges**.

---

## 📌 Table of Contents

1. What is Two Pointers?
2. Types of Two Pointers
3. What is Sliding Window?
4. Fixed vs Variable Sliding Window
5. Common Templates
6. When to Use Which Pattern
7. Classic Problems List
8. Common Mistakes
9. Key Takeaways

---

## 1️⃣ What is Two Pointers?

**Two Pointers** is a technique where we use **two indices** to traverse a data structure (usually an array or string) in a coordinated way.

### Why use it?

* Reduces brute‑force **O(n²)** solutions to **O(n)**
* Works well with **sorted arrays**, **pairs**, and **ranges**

---

## 2️⃣ Types of Two Pointers

### 🔹 Type 1: Opposite Direction Pointers

* One pointer starts from the **beginning**
* One pointer starts from the **end**

```cpp
int l = 0, r = n - 1;
while (l < r) {
    if (condition) l++;
    else r--;
}
```

**Used in:**

* Two Sum (sorted array)
* Palindrome check
* Container With Most Water

---

### 🔹 Type 2: Same Direction (Fast & Slow)

* Both pointers move **forward**
* One pointer depends on the other

```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (valid(nums[fast])) {
        nums[slow++] = nums[fast];
    }
}
```

**Used in:**

* Remove duplicates
* Remove elements
* Cycle detection

---

## 3️⃣ What is Sliding Window?

Sliding Window is a **special case of two pointers** used when working with **contiguous subarrays or substrings**.

Instead of recalculating values for each window, we:

* **Add one element** when expanding
* **Remove one element** when shrinking

➡️ Guarantees **O(n)** time

---

## 4️⃣ Fixed vs Variable Sliding Window

### 🟦 Fixed‑Size Sliding Window

* Window size is **constant (k)**
* Add one element, remove one element

```cpp
if (r - l + 1 == k) {
    updateAnswer();
    remove(nums[l]);
    l++;
}
```

**Used in:**

* Maximum sum subarray of size k
* Sliding window maximum

---

### 🟩 Variable‑Size Sliding Window

* Window size **changes dynamically**
* Used when constraints must be satisfied

```cpp
while (windowInvalid()) {
    shrinkWindow();
}
```

**Used in:**

* Longest substring with at most K distinct characters
* Minimum window substring

---

## 5️⃣ Core Sliding Window Templates

### 🔹 Longest Window (At Most K)

```cpp
for (int r = 0; r < n; r++) {
    add(nums[r]);
    while (invalid()) remove(nums[l++]);
    ans = max(ans, r - l + 1);
}
```

---

### 🔹 Minimum Window

```cpp
for (int r = 0; r < n; r++) {
    add(nums[r]);
    while (valid()) {
        ans = min(ans, r - l + 1);
        remove(nums[l++]);
    }
}
```

---

### 🔹 Count Subarrays (Exactly K)

```cpp
exactlyK = atMostK(k) - atMostK(k - 1);
```

---

## 6️⃣ When to Use Which Pattern?

| Problem Type           | Technique               |
| ---------------------- | ----------------------- |
| Sorted array pairs     | Two pointers (opposite) |
| Remove / compress      | Fast & slow pointers    |
| Fixed window size      | Sliding window (fixed)  |
| At most / no more than | Sliding window + while  |
| Minimum window         | Shrink while valid      |
| Exactly K              | atMost(K) − atMost(K−1) |

---

## 7️⃣ Classic Problems to Practice

### Two Pointers

* Two Sum II
* Container With Most Water
* Valid Palindrome
* Remove Duplicates from Sorted Array

### Sliding Window

* Longest Substring Without Repeating Characters
* Longest Substring with At Most K Distinct Characters
* Minimum Window Substring
* Subarrays with Sum K
* Sliding Window Maximum

---

## 8️⃣ Common Mistakes ❌

* Using `if` instead of `while` when shrinking
* Updating answer before restoring validity
* Confusing **longest** and **minimum** window logic
* Using sliding window when negative numbers exist (needs prefix sum)

---

## 9️⃣ Key Takeaways ⭐

* Two pointers reduce time complexity dramatically
* Sliding window works only on **contiguous** data
* **Longest → grow greedily**
* **Minimum → shrink greedily**
* `while` restores constraints, `if` does not

