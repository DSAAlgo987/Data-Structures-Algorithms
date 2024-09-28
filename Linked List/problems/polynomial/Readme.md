# Polynomial Operations in C

This program implements polynomial operations using a linked list representation in C. It allows users to create polynomials, display them, and perform addition of two polynomials.

## Visual Representation

The following image illustrates the concept of polynomial addition:

![Polynomial Addition](https://media.geeksforgeeks.org/wp-content/uploads/Addition-of-two-polynomial.png)

*Image source: GeeksforGeeks*

## Features

- Create polynomials by entering terms (coefficient and power)
- Display polynomials in a readable format
- Add two polynomials

## Data Structure

The program uses a linked list to represent polynomials. Each node in the list contains:
- Coefficient (integer)
- Power (integer)
- Pointer to the next term

## Functions

1. `createNode`: Creates a new node for a polynomial term
2. `createPolynomial`: Allows user to input a polynomial
3. `displayPolynomial`: Displays a polynomial in standard algebraic notation
4. `addPolynomials`: Adds two polynomials and returns the result

## Limitations

- The program assumes input polynomials are in descending order of power
- It does not handle floating-point coefficients

## Future Improvements

- Implement polynomial multiplication
- Add support for floating-point coefficients
- Implement polynomial division
- Add error handling for invalid inputs
- Implement memory deallocation to prevent memory leaks

## Contributing

Feel free to fork this project and submit pull requests with improvements or additional features.

## License

This project is open source and available under the [MIT License](LICENSE).