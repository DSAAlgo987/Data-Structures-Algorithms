# Singly Linked List

A singly linked list is a fundamental data structure in computer science, consisting of a sequence of elements where each element points to the next one in the sequence.

<div align="center">
<img src="https://media.geeksforgeeks.org/wp-content/uploads/singly-linkedlist.png" alt="Singly Linked List">
</div>

## Features

- Dynamic size
- Efficient insertion and deletion at the beginning
- Sequential access to elements

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
## Structure of a Singly Linked List Node
Each node in a singly linked list consists of:
1. **Data**: The value stored in the node.
2. **Next Pointer**: A reference to the next node in the list.

### Node Representation
```c
struct Node {
    int data;
    struct Node* next;
};

