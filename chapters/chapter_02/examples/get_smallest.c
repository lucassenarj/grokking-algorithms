#include <stdio.h>

int get_smallest(int *nums, int size);

int main(void)
{
    int nums[] = {23, 45, 59, 85, 18, 77};
    
    printf("\nThe index to smallest number is: %d\n", get_smallest(nums, 6)); // expect result: 4
}

int get_smallest(int *nums, int size)
{
    int i;

    // define initial smallest
    int smallest = nums[0];

    // define initial index
    int index = 0;

    for (i = 0; i < size; i++)
    {
        // verify if current number is smaller then smallest
        if (nums[i] < smallest)
        {
            // define new smallest 
            smallest = nums[i];

            // define current index as smallest index
            index = i;
        }
    }

    // return smallest index
    return index;
}