#include <stdio.h>

void regressive(int i);

int main(void)
{
    int i = 5;

    regressive(i);
}

void regressive(int i) {
    printf("%d\n", i);
    // base-case
    if (i <= 1) {
        return;
    }
    // recursive case
    regressive(i-1);
}