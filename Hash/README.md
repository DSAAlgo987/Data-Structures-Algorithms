<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/20240508162721/Components-of-Hashing.webp" alt="Hashing Components">
</p>

## Definition

*Hashing* is a technique used to uniquely identify a specific object from a group of similar objects. In data structures, it is primarily used to map data to specific locations in memory for efficient retrieval.

Hashing involves converting a given key into another value, which is then used as an index to store the desired data. A hash function is employed to compute this index, providing a quick way to access elements based on their keys.

---

## Key Concepts

1. *Hash Function*  
   A *hash function* takes an input (or 'key') and returns an integer, which is usually used as an index where the data is stored in the hash table. A good hash function minimizes the chances of collisions (where different keys produce the same index).

2. *Hash Table*  
   A *hash table* is a data structure that implements an associative array, allowing storage of key-value pairs. The position of each key is determined by applying a hash function to it.

3. *Collisions*  
   *Collisions* occur when two different keys produce the same hash index. Various techniques, such as chaining and open addressing, are used to resolve collisions.

---

## Hashing Techniques

1. *Chaining*  
   In this technique, each index in the hash table points to a linked list of entries that hash to the same index. This allows multiple entries to exist at a single index without overwriting each other.

2. *Open Addressing*  
   Open addressing tries to find another open slot within the hash table when a collision occurs. Methods for open addressing include:
   - *Linear Probing*: Checking the next slot sequentially until an empty slot is found.
   - *Quadratic Probing*: Using a quadratic function to find the next slot.
   - *Double Hashing*: Using a second hash function to determine the next slot.

---

## Operations and Time Complexity

1. *Insertion*  
   Insert a key-value pair into the hash table using the hash function to determine its index.  
   *Average Time Complexity*: O(1)

2. *Search*  
   Retrieve a value associated with a key by locating the index using the hash function.  
   *Average Time Complexity*: O(1)

3. *Deletion*  
   Remove a key-value pair from the hash table by locating it using the hash function and then deleting it.  
   *Average Time Complexity*: O(1)
