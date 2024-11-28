# Merge Sort

Merge Sort is a divide-and-conquer algorithm that splits an array into halves, recursively sorts each half, and then merges the sorted halves back together.

<p align="center">
  <img src="https://startutorial.com/img/merge-sort-split.jpg" alt="Merge Sort Illustration" width="500" height="500">
</p>

## How Merge Sort Works
1. **Divide**: Split the array into two halves.
2. **Conquer**: Recursively sort each half.
3. **Merge**: Combine the sorted halves into a single sorted array.

## Example
Consider an array `[38, 27, 43, 3, 9, 82, 10]`. Using merge sort:
1. Split into `[38, 27, 43, 3]` and `[9, 82, 10]`.
2. Continue splitting until single-element arrays are obtained.
3. Merge back step by step until the array is fully sorted: `[3, 9, 10, 27, 38, 43, 82]`.

## Time and Space Complexity

| **Complexity** | **Best Case** | **Average Case** | **Worst Case** |
|----------------|---------------|------------------|----------------|
| **Time**       | O(n log n)    | O(n log n)       | O(n log n)     |
| **Space**      | O(n)          | O(n)             | O(n)           |
