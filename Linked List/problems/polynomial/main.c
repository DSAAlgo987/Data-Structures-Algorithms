#include <stdio.h>
#include "operations.h"
int main()
{
    start1 = create(start1);
    start2 = create(start2);

    add();    
    displayPolynomial(result);
    
    result = NULL;
    subtract();
    displayPolynomial(result);

    return 0;
}