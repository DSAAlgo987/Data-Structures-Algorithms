# Sorting Algorithms

![Sorting Algorithm Banner](https://media.geeksforgeeks.org/wp-content/uploads/20240401174827/sorting-algorithm-banner.webp)

This repository contains the implementations of various sorting algorithms. Sorting algorithms are used to rearrange a collection of elements (e.g., numbers) into a particular order (e.g., ascending or descending). These implementations are optimized for clarity and ease of understanding.

---

## Table of Contents
1. [Introduction](#introduction)
2. [Sorting Algorithms](#sorting-algorithms)
   - [Insertion Sort](#insertion-sort)
   - [Selection Sort](#selection-sort)
   - [Quick Sort](#quick-sort)
   - [Merge Sort](#merge-sort)
   - [Radix Sort](#radix-sort)
3. [Time Complexity Comparison](#time-complexity-comparison)
4. [Usage](#usage)
5. [Contact](#contact)

---

## Introduction

Sorting is a fundamental operation in computer science, and different algorithms are designed to handle specific data types and use cases. The algorithms in this repository are implemented for educational purposes to help understand how they work.

---

## Sorting Algorithms

### Insertion Sort
- **Description**: Insertion Sort is a simple sorting algorithm that builds the final sorted array one element at a time. It is efficient for small datasets or partially sorted data.

### Selection Sort
- **Description**: Selection Sort repeatedly selects the smallest (or largest) element from the unsorted portion of the list and swaps it with the first unsorted element.

### Quick Sort
- **Description**: Quick Sort is a divide-and-conquer algorithm that partitions the array into smaller subarrays based on a pivot and sorts them recursively.

### Merge Sort
- **Description**: Merge Sort is a stable, divide-and-conquer sorting algorithm that splits the array into halves, sorts them, and then merges them back together.

### Radix Sort
- **Description**: Radix Sort is a non-comparative sorting algorithm that processes the digits of numbers from the least significant digit to the most significant digit.

---

## Time Complexity Comparison

| Algorithm       | Best Case Time Complexity | Average Case Time Complexity | Worst Case Time Complexity | Space Complexity |
|------------------|----------------------------|-------------------------------|----------------------------|-------------------|
| **Insertion Sort** | O(n)                     | O(n²)                        | O(n²)                     | O(1)              |
| **Selection Sort** | O(n²)                   | O(n²)                        | O(n²)                     | O(1)              |
| **Quick Sort**     | O(n log n)              | O(n log n)                   | O(n²)                     | O(log n)          |
| **Merge Sort**     | O(n log n)              | O(n log n)                   | O(n log n)                | O(n)              |
| **Radix Sort**     | O(nk)                   | O(nk)                        | O(nk)                     | O(n + k)          |

> **Note:** `n` is the number of elements, and `k` is the number of digits in the largest number for Radix Sort.

---

## Usage

Each sorting algorithm is implemented in a separate file. You can compile and run the code to test its functionality on various datasets. Example usage:

```bash
# Example to compile and run Insertion Sort
gcc insertion_sort.c -o insertion_sort
./insertion_sort


