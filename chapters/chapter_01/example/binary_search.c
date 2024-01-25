#include <stdio.h>

const int SIZE = 100;

int search(int arr[], int item, int size);

int main(void)
{
    int arr[SIZE];

    for (int i = 0; i < 100; i++)
    {
        arr[i] = i;
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    int founded = search(arr, 105, size);

    if (founded > 0)
    {
        printf("Founded: %i\n", founded);
        return 0;
    }
    printf("Not Founded\n");
    return 1;
    
}

int search(int arr[], int item, int size)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int half = (low + high) / 2;
        int guess = arr[half];
        if (guess == item)
        {
            return half;
        }
        if (guess > item)
        {
            high = half - 1;
        } else
        {
            low = half + 1;
        }
    }
    return 0;
}