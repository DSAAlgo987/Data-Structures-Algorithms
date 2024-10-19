## Tree Data Structures

A **Tree** is a widely used data structure that simulates a hierarchical tree structure, with a root value and subtrees of children represented as a set of linked nodes.

<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/20240811023816/Introduction-to-Binary-Tree.webp" alt="Tree Representation">
</p>

### Types of Trees Implemented

- **Binary Tree**  
  A tree data structure in which each node has at most two children referred to as the left child and the right child.
  
- **Binary Search Tree (BST)**  
  A binary tree in which all the left descendants of a node are smaller than the node, and all the right descendants are larger.

- **AVL Tree**  
  A self-balancing binary search tree where the difference between heights of left and right subtrees cannot be more than one for all nodes.

### Operations

1. **Creation**
   - Inserting nodes into the tree (starting from the root).
   - Defining rules for left and right children based on the type of tree (binary, BST, AVL).

2. **Traversal**
   - **Inorder**: Left, Root, Right
   - **Preorder**: Root, Left, Right
   - **Postorder**: Left, Right, Root
   - **Level Order Traversal**

3. **Search**
   - Searching for a node in the tree using Binary Search (in the case of BST).

4. **Insertion**
   - Adding new nodes to the tree, maintaining the properties of the specific tree (BST, AVL, etc.).

5. **Deletion**
   - Removing nodes from the tree, ensuring that the tree's properties remain intact after deletion.

6. **Rotation** (for AVL Tree)
   - **Single Rotation** (Left or Right)
   - **Double Rotation** (Left-Right or Right-Left)

7. **Balancing** (for AVL Tree)
   - Re-balancing the tree after insertions or deletions to maintain height balance.

### Usage

You can find implementations of these tree structures in the respective directories:

- [Binary Tree](./Tree/Binary%20Tree)
- [Binary Search Tree (BST)](./Tree/BST)
- [AVL Tree](./Tree/AVL)

Explore the source code to understand how each operation is implemented.
