# Chaining in Hashing

Chaining is a method used to resolve hash collisions in hash tables. In this method, each bucket (or slot) of the hash table stores a linked list of all elements that hash to the same index. When a collision occurs, the element is simply added to the linked list at that index.

<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2015/07/hashChaining1.png" alt="Chaining in Hashing">
</p>

### Time and Space Complexity

| **Operation**      | **Average Case** | **Worst Case** |
|--------------------|------------------|----------------|
| **Search**         | O(1)             | O(n)           |
| **Insert**         | O(1)             | O(n)           |
| **Delete**         | O(1)             | O(n)           |

### Explanation

- **Search**: On average, the search operation takes constant time since elements are stored in a linked list in each bucket. However, in the worst case, all elements could hash to the same bucket, resulting in a linear search.
  
- **Insert**: Insertion also takes constant time on average. If a collision occurs, the element is added to the linked list at the corresponding bucket.
  
- **Delete**: Deletion follows the same approach as the search operation: O(1) on average but could degrade to O(n) in the worst case.

### Space Complexity

The space complexity of chaining in hashing is O(n), where n is the number of elements in the hash table. This is because, in the worst case, all elements can be stored in a single linked list.
