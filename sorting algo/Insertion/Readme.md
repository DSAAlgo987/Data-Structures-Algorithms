# Insertion Sort

![Insertion Sort Banner](https://media.geeksforgeeks.org/wp-content/uploads/20240408140301/Insertion-Sort.webp)

This repository contains the implementation of **Insertion Sort**, a simple and intuitive sorting algorithm that builds the final sorted array one element at a time. It is particularly efficient for small datasets or partially sorted data.

---

## Table of Contents
1. [Introduction](#introduction)
2. [Algorithm Steps](#algorithm-steps)
3. [Time and Space Complexity](#time-and-space-complexity)
4. [Advantages and Disadvantages](#advantages-and-disadvantages)
5. [Usage](#usage)
6. [Contact](#contact)

---

## Introduction

Insertion Sort is a comparison-based sorting algorithm that works by dividing the input into a sorted and an unsorted part. Elements from the unsorted part are picked one at a time and inserted into their correct position in the sorted part.  

---

## Algorithm Steps

1. Start with the second element (index 1), assuming the first element is already sorted.
2. Compare the current element with the elements in the sorted part of the array.
3. Shift all larger elements in the sorted part to the right to make room for the current element.
4. Insert the current element into its correct position.
5. Repeat until all elements are sorted.

**Example:**  
For an array `[5, 3, 4, 1, 2]`, the algorithm works as follows:  
- Pass 1: `[3, 5, 4, 1, 2]`  
- Pass 2: `[3, 4, 5, 1, 2]`  
- Pass 3: `[1, 3, 4, 5, 2]`  
- Pass 4: `[1, 2, 3, 4, 5]`

---

## Time and Space Complexity

| Case          | Time Complexity | Explanation                                          |
|---------------|-----------------|------------------------------------------------------|
| **Best Case** | O(n)            | Array is already sorted; only one comparison per element. |
| **Average Case** | O(n²)         | Each element is compared with all previous elements in the worst case. |
| **Worst Case** | O(n²)          | Array is sorted in reverse order; maximum comparisons are needed. |
| **Space Complexity** | O(1)      | In-place sorting algorithm, no additional space is required. |

---

## Advantages and Disadvantages

### Advantages:
- Simple and easy to implement.
- Efficient for small datasets or nearly sorted data.
- Stable sorting algorithm (preserves the order of equal elements).

### Disadvantages:
- Inefficient for large datasets due to O(n²) time complexity.

---

## Usage

To compile and run the code for **Insertion Sort**, use the following commands:

```bash
# Compile the code
gcc insertion_sort.c -o insertion_sort

# Run the executable
./insertion_sort
