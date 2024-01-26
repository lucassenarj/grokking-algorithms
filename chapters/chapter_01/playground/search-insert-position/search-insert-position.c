#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target);

int main(void)
{
    int nums[] = {1, 3, 5, 6};

    printf("%d\n", searchInsert(nums, 4, 5)); // expected output: 5
    printf("%d\n", searchInsert(nums, 4, 2)); // expected output: 2
    printf("%d\n", searchInsert(nums, 4, 7)); // expected output: 7
    printf("%d\n", searchInsert(nums, 4, 0)); // expected output: 0
}

int searchInsert(int *nums, int numsSize, int target)
{
    /*
        if target is founded, return the index where the target is
        else, return the index where target should be if is ordered array
    */
    int low = 0;
    int high = numsSize - 1;
    int mid;
    int current;

    do
    {
        mid = (low + high) / 2;
        current = nums[mid];

        if (current == target) {
            return mid;
        } else if (current > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    } while (low <= high);

    if (current > target) {
        return mid;
    }

    return mid + 1;
}
