# Circular Linked List

A circular linked list is a variation of a linked list where the last node points back to the first node, forming a circular structure. This allows for continuous traversal of the list.

<div align="center">
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20240402130347/circular-linked-list-copy.webp" alt="Circular Linked List">
</div>

## Features

- Dynamic size
- Continuous traversal of elements
- Efficient insertion and deletion at any point

## Basic Operations

1. Insertion
   - At the beginning
   - At the end
   - At a specific position

2. Deletion
   - From the beginning
   - From the end
   - From a specific position

3. Traversal
   - Print all elements

4. Search
   - Find an element by value

## Structure of a Circular Linked List Node
Each node in a circular linked list consists of:
1. **Data**: The value stored in the node.
2. **Next Pointer**: A reference to the next node in the list.

### Node Representation
```c
struct Node {
    int data;
    struct Node* next;
};
