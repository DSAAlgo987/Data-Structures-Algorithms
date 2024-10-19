# Binary Tree

A **Binary Tree** is a tree data structure in which each node has at most two children referred to as the left child and the right child. It is one of the simplest forms of hierarchical data structures used in computer science.

<p align="center">
  <img src="https://datastructuresamy.wordpress.com/wp-content/uploads/2018/03/trees.png" alt="Binary Tree Representation">
</p>

## Overview

In a Binary Tree, each node contains:
- A data element
- A pointer to the left child node
- A pointer to the right child node

The tree starts at a root node, and each node can have a left and/or right child, recursively creating the structure of the tree.

## Operations

The following operations are supported for the **Binary Tree**:

1. **Node Creation**  
   Creating a new node that contains data and points to `NULL` for its left and right children.

2. **Insertion**  
   Inserting a node at the correct position based on certain rules (e.g., level order insertion).

3. **Traversal**  
   Traversing the binary tree in different ways:
   - Inorder (Left, Root, Right)
   - Preorder (Root, Left, Right)
   - Postorder (Left, Right, Root)
   - Level Order (Breadth-First)

4. **Searching**  
   Finding a node in the tree by comparing the data in each node with the target data.

5. **Counting Nodes**  
   Counting the total number of nodes present in the binary tree.

6. **Height/Depth of the Tree**  
   Determining the height or depth of the binary tree, which is the longest path from the root to a leaf node.

7. **Deletion**  
   Removing a node from the tree while maintaining the structure.

8. **Level Order Traversal using Queue**  
   Performing level order traversal (Breadth-First Search) using a queue to visit nodes level by level.

## Additional Information

Binary Trees are fundamental in computer science and are used in various applications such as searching, sorting, and hierarchical data representation.
