# Quick Sort

Quick Sort is a divide-and-conquer algorithm. It picks an element as a pivot and partitions the given array around the pivot. The array is then recursively sorted on either side of the pivot.

<p align="center">
  <img src="https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/01/QuickSort2.png" alt="Quick Sort Illustration">
</p>

## How Quick Sort Works
1. **Choose a pivot**: Select an element from the array (commonly the last element) as the pivot.
2. **Partition**: Rearrange the array so that elements smaller than the pivot are on the left, and elements larger are on the right.
3. **Recursively sort**: Recursively apply the same process to the left and right subarrays.

## Example
Consider the array `[10, 80, 30, 90, 40, 50, 70]` and choosing 70 as the pivot:
1. Partition the array around 70: `[10, 30, 40, 50, 70, 90, 80]`.
2. Recursively sort the left and right subarrays: `[10, 30, 40, 50]` and `[80, 90]`.
3. Final sorted array: `[10, 30, 40, 50, 70, 80, 90]`.

## Time and Space Complexity

| **Complexity** | **Best Case** | **Average Case** | **Worst Case** |
|----------------|---------------|------------------|----------------|
| **Time**       | O(n log n)    | O(n log n)       | O(n²)          |
| **Space**      | O(log n)      | O(log n)         | O(n)           |
