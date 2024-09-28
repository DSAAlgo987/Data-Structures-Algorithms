#include <stdio.h>
#include "operations.h"

// Polynomial : P(x) = 4x^2 + 7x^3 + 8x^5 + 5x^4  + 5x + 5
// P(x) = 8x^5 + 5x^4 + 7x^3 + 4x^2 + 5x + 5

int main()
{

	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* result = NULL;

	printf("\nEnter the corresponding data:-\n");
	printf("\nFirst polynomial:\n");
	readPolynomial(&first);
	displayPolynomial(first);
	printf("\nSecond polynomial:\n");
	readPolynomial(&second);
	displayPolynomial(second);
	addPolynomials(&result, first, second);
	displayPolynomial(result);
	return 0;
}
