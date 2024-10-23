# Swapping Two Variables Using XOR in C

This project demonstrates how to swap two variables using the XOR bitwise operation in **C**, without using a third variable. The XOR technique allows us to swap values efficiently without the need for extra memory.

<div align="center">
    <img src="./swapping%20image.PNG" alt="Swapping Image" />
</div>


## How XOR Works

The XOR (Exclusive OR) operation is a bitwise operator that compares two bits:
- If the bits are different, the result is `1`.
- If the bits are the same, the result is `0`.

Using this property, we can swap two variables without the need for a third variable. The process for swapping two variables `A` and `B` is as follows:

1. Perform the operation: `A = A ^ B`.
2. Then, perform: `B = A ^ B` (this gives the original value of `A` to `B`).
3. Finally, perform: `A = A ^ B` (this assigns the original value of `B` to `A`).

## Example Code in C

```c
#include <stdio.h>

int main() {
    int A = 5, B = 10;

    // Display initial values
    printf("Before swapping: A = %d, B = %d\n", A, B);

    // XOR swap logic
    A = A ^ B;  // A now holds A ^ B
    B = A ^ B;  // B now holds the original value of A
    A = A ^ B;  // A now holds the original value of B

    // Display swapped values
    printf("After swapping: A = %d, B = %d\n", A, B);

    return 0;
}

Output : 

Before swapping: A = 5, B = 10
After swapping: A = 10, B = 5

