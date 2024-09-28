# Sparse Matrix Program

This program demonstrates the creation and display of a **sparse matrix** using linked lists in C. A sparse matrix is a matrix that contains a large number of zero elements. Instead of storing all elements (including zeros), this program efficiently stores and represents only the non-zero elements using a list of lists.

## Features
- **Sparse Matrix Creation**: The program allows you to create a sparse matrix by specifying the number of non-zero elements for each row, along with their column positions and values.
- **Display Sparse Matrix**: The sparse matrix is displayed in its original matrix form, filling in zero values for elements that are not explicitly stored.

## Example
Here's how a sparse matrix is represented in memory using a list of lists:

![Sparse Matrix Representation](https://media.geeksforgeeks.org/wp-content/uploads/Sparse-Matrix-List-of-Lists2.png)

## How it Works
1. **Structure Definition**: The program uses a `Node` structure to store the column index, data (value), and the pointer to the next non-zero element in the row.
2. **Matrix Creation**: Users input the number of rows and columns, and specify the non-zero elements for each row.
3. **Matrix Display**: The sparse matrix is displayed with appropriate spacing, showing zeroes in the positions where no value is stored.

## Code Structure
- `createNode(int col, int data)`: Creates a new node to store non-zero elements.
- `createSparseMatrix(struct Node** A, int m, int n)`: Creates the sparse matrix by taking user input for non-zero values.
- `displaySparseMatrix(struct Node** A, int m, int n)`: Displays the sparse matrix in its full form, filling zeroes where necessary.

## Usage
1. Compile the program:
    ```bash
    gcc sparse_matrix.c -o sparse_matrix
    ```
2. Run the program:
    ```bash
    ./sparse_matrix
    ```
3. Input the number of rows, columns, and the non-zero elements to create and display the sparse matrix.

## Conclusion
This program offers an efficient way to handle sparse matrices, reducing memory usage by storing only the non-zero elements using linked lists.