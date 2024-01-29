#include <stdio.h>
#include <limits.h>

const int size = 5;

int get_smallest(int *nums);
int *selection_sort(int *nums);

int main(void)
{
    int i;
    int nums[] = {5, 3, 6, 2, 10};
    
    int *sorted = selection_sort(nums);

    printf("\nSorted numbers: "); // expected result: 2, 3, 5, 6, 10
    for (i = 0; i < size; i++)
    {
        printf("%d, ", sorted[i]);
    }
    printf("\n");
}

int get_smallest(int *nums)
{
    int i;

    // define very high number for smallest value, for the first interaction, the current values always be smaller then smallest
    int smallest = INT_MAX;

    // define initial index
    int index = 0;

    for (i = 0; i < size; i++)
    {
        int current = nums[i];
        if (nums[i] > 0) {
            // verify if current number is smaller then smallest
            if (current < smallest)
            {
                // define new smallest 
                smallest = current;

                // define current index as smallest index
                index = i;
            }
        }
    }

    // return smallest index
    return index;
}

int *selection_sort(int *nums)
{
    int i;

    /*
        Creating new array with same size.
        Using keyword static because C doens't allow to return the address of a local variable to outside of the function.
        A static int variable remains in memory while the program is running.
        A normal or auto variable is destroyed when a function call where the variable was declared is over.
    */
    static int sorted[size];

    for (i = 0; i < size; i++)
    {
        // get index of the smallest number in array
        int smallest = get_smallest(nums);

        // append smallest to new array
        sorted[i] = nums[smallest];

        // remove item from current array
        nums[smallest] = 0;
    }

    return sorted;
}
