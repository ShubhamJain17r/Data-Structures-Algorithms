# Binary Search

Binary Search is an efficient algorithm for finding a target value in a **sorted** array or list.  
It works by repeatedly dividing the search interval in half.

---

## 📌 Requirements
- The input data **must be sorted**
- Random access to elements (arrays, vectors)

---

## ⚙️ How It Works
1. Compare the target value with the middle element.
2. If equal → target found.
3. If target is smaller → search left half.
4. If target is larger → search right half.
5. Repeat until found or the range becomes empty.

---

## ⏱️ Time & Space Complexity

| Case        | Time Complexity |
|-------------|-----------------|
| Best        | O(1)            |
| Average     | O(log n)        |
| Worst       | O(log n)        |

- **Space Complexity**
  - Iterative: `O(1)`
  - Recursive: `O(log n)` (call stack)

---

## Why Binary Search is O(log n)

Binary Search has **logarithmic time complexity** because:

- Each comparison **reduces the search space by half**
- After 1 step → `n / 2` elements remain
- After 2 steps → `n / 4`
- After 3 steps → `n / 8`
- After `k` steps → `n / 2^k`

The algorithm stops when:
`n / 2^k = 1`

Solving for `k`:
`2 ^ k = n`, `k = log₂(n)`

Thus, the number of operations grows proportionally to **log₂(n)**, giving: Time Complexity = O(log n)

## 🧠 Algorithm (Iterative)

```cpp
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found
}
```

## 🔁 Recursive Version
```cpp
int binarySearch(const std::vector<int>& arr, int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, right, target);
}
```

## ✅ Example
```cpp
std::vector<int> data = {1, 3, 5, 7, 9, 11};
int index = binarySearch(data, 7);
// Output: index = 3
```