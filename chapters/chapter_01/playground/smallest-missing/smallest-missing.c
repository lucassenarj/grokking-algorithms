#include <stdio.h>

int search(int *nums, int size);
int recursiveSearch(int *nums, int low, int high);

int main(void)
{
    int nums1[] = {0, 1, 2, 6, 9, 11, 15}; // expected result 3
    int nums2[] = {1, 2, 3, 4, 6, 9, 11, 15}; // expected result 0
    int nums3[] = {0, 1, 2, 3, 4, 5, 6}; // expected result 7

    int size = sizeof(nums1) / sizeof(nums1[0]);
    int low = 0;
    int high = size;

    // non-recursive binary search
    printf("The smallest missing element is %d\n", search(nums1, size));

    // update size value
    size = sizeof(nums2) / sizeof(nums2[0]);
    printf("The smallest missing element is %d\n", search(nums2, size));

    // update size value
    size = sizeof(nums3) / sizeof(nums3[0]);
    printf("The smallest missing element is %d\n\n", search(nums3, size));


    // RECURSIVE CALLS //
    printf("The smallest missing element is %d\n", recursiveSearch(nums1, low, high));

    // update high value
    high = sizeof(nums2) / sizeof(nums2[0]);
    printf("The smallest missing element is %d\n", recursiveSearch(nums2, low, high));

    // update high value
    high = sizeof(nums3) / sizeof(nums3[0]);
    printf("The smallest missing element is %d\n\n", recursiveSearch(nums3, low, high));
}

int search(int *nums, int size)
{
    int low = nums[0];
    int high = size - 1;
    int mid;

    while (low <= high) {
        // mid
        mid = (low + high) / 2;

        // pick a number
        int current = nums[mid];

        if (mid == current) {
            low = mid + 1; // smallest missing is on the right side of array
        } else {
            high = mid - 1; // smallest missing is on the left side of array
        }
    }
    return mid + 1;
}

int recursiveSearch(int *nums, int low, int high)
{
    // base case
    if (low > high) {
        return low;
    }
    // define mid
    int mid = (low + high) / 2;

    // pick the mid position in array
    int current = nums[mid];

    if (mid == current) {
        // smallest missing is on the right side of array
        low = mid + 1;

        // recursive call
        return recursiveSearch(nums, low, high);
    } else {
         // smallest missing is on the left side of array
        high = mid - 1;

        // recursive call
        return recursiveSearch(nums, low, high);
    }
}