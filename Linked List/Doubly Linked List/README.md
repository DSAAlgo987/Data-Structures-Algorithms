# Doubly Linked List

A doubly linked list is a more advanced data structure than a singly linked list, where each node contains a reference to both the next and the previous node in the sequence.

<div align="center">
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20240223174514/Doubly-Linked-List-in-Data-Structure.webp" alt="Doubly Linked List">
</div>

## Features

- Dynamic size
- Efficient insertion and deletion at both ends
- Bidirectional traversal (forward and backward)

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
   - Print all elements (forward and backward)

4. Search
   - Find an element by value

## Structure of a Doubly Linked List Node
Each node in a doubly linked list consists of:
1. **Data**: The value stored in the node.
2. **Next Pointer**: A reference to the next node in the list.
3. **Previous Pointer**: A reference to the previous node in the list.

### Node Representation
```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
