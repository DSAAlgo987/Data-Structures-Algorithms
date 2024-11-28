# Linear Probing in Hashing

Linear Probing is a collision resolution technique used in open addressing to resolve hash collisions. When a collision occurs, linear probing checks the next available slot in a sequential manner (i.e., it moves linearly through the hash table until an empty slot is found).

<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/Linear-Probing-1-1.jpg" alt="Linear Probing in Hashing">
</p>

### Time and Space Complexity

| **Operation**      | **Average Case** | **Worst Case** |
|--------------------|------------------|----------------|
| **Search**         | O(1)             | O(n)           |
| **Insert**         | O(1)             | O(n)           |
| **Delete**         | O(1)             | O(n)           |

### Explanation

- **Search**: In linear probing, the search operation can be very efficient if the load factor is low. However, if many slots are occupied, it might take longer, resulting in O(n) time complexity in the worst case.
  
- **Insert**: Insertions are generally efficient with linear probing, but in cases where the hash table is nearing its capacity, insertions might degrade to O(n) as the algorithm will need to probe multiple slots to find an available one.
  
- **Delete**: Deletion works similarly to insertion. In cases of full tables or long chains of collisions, the time complexity may degrade to O(n).

### Space Complexity

The space complexity of linear probing is O(n), where n is the number of elements in the hash table. This is because the space is determined by the size of the hash table itself, and additional space is not required beyond the table.
