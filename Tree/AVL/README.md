# AVL Trees

## Introduction
An AVL tree is a self-balancing binary search tree where the difference in heights between the left and right subtrees (the balance factor) is at most 1 for every node. This property ensures that the tree remains approximately balanced, providing efficient performance for operations such as insertion, deletion, and lookup.

## Properties of AVL Trees
1. **Balance Factor**: For any node in the AVL tree, the balance factor is defined as:
   \[
   \text{Balance Factor} = \text{Height of Left Subtree} - \text{Height of Right Subtree}
   \]
   The balance factor can be -1, 0, or 1.

2. **Height-Balancing**: The AVL tree maintains its balance by performing rotations during insertions and deletions.

## AVL Tree Rotations
When the balance factor becomes greater than 1 or less than -1 after an insertion or deletion, rotations are performed to restore the balance.

### Types of Rotations
1. **Single Right Rotation**
2. **Single Left Rotation**
3. **Left-Right Rotation**
4. **Right-Left Rotation**

## AVL Tree Insertion
When inserting a node into an AVL tree, the following steps are followed:
1. Insert the node as you would in a regular binary search tree.
2. Update the heights of the ancestors of the newly inserted node.
3. Check the balance factors of the ancestors.
4. Perform the appropriate rotation(s) if necessary.

### AVL Tree Insertion Example
<div align="center">

![AVL Insertion](https://media.geeksforgeeks.org/wp-content/uploads/AVL-Insertion-1.jpg)

</div>

In the image above, we can see the process of inserting nodes into an AVL tree and how rotations are applied to maintain balance.

## Conclusion
AVL trees are crucial for maintaining sorted data and ensuring efficient data retrieval. They offer better performance than unbalanced trees, especially in scenarios with frequent insertions and deletions.
