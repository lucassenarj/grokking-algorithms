#include <stdio.h>

int factorial(int i);

int main(void)
{
    printf("Factorial of 5 is: %d\n", factorial(5)); // expected result 120
    printf("Factorial of 3 is: %d\n", factorial(3)); // expected result 6
}

int factorial(int i)
{
    // base-case
    if (i == 1) {
        return 1;
    }

    // recursive case
    return i * factorial(i-1);
}
