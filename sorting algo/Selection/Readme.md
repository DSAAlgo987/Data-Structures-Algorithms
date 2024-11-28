# Selection Sort

Selection Sort is a simple comparison-based sorting algorithm. It repeatedly selects the minimum (or maximum) element from the unsorted portion of the array and swaps it with the first unsorted element.

<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/20230706105535/Selection-sort.png" alt="Selection Sort Illustration">
</p>

## How Selection Sort Works
1. **Find the minimum element**: Traverse the entire unsorted part of the array and find the minimum element.
2. **Swap**: Swap the found minimum element with the first element of the unsorted part.
3. **Repeat**: Move the boundary of the sorted and unsorted parts of the array by one and repeat the process until the entire array is sorted.

## Example
Consider the array `[64, 25, 12, 22, 11]`:
1. Find the minimum (11), and swap it with the first element: `[11, 25, 12, 22, 64]`.
2. Find the minimum of the remaining array (12), and swap it with the second element: `[11, 12, 25, 22, 64]`.
3. Continue this process until the entire array is sorted: `[11, 12, 22, 25, 64]`.

## Time and Space Complexity

| **Complexity** | **Best Case** | **Average Case** | **Worst Case** |
|----------------|---------------|------------------|----------------|
| **Time**       | O(n²)         | O(n²)            | O(n²)          |
| **Space**      | O(1)          | O(1)             | O(1)           |
