# Binary Search Exercise
- _26/01/2024_
- _[Find the smallest missing element from a sorted array](https://www.techiedelight.com/find-smallest-missing-element-sorted-array/)_

## Find the smallest missing element from a sorted array
Given a sorted array of non-negative distinct integers, find the smallest missing non-negative element in it.

For example,

```
Input:  nums[] = [0, 1, 2, 6, 9, 11, 15]
Output: The smallest missing element is 3  

Input:  nums[] = [1, 2, 3, 4, 6, 9, 11, 15]
Output: The smallest missing element is 0  

Input:  nums[] = [0, 1, 2, 3, 4, 5, 6]
Output: The smallest missing element is 7
```

A simple analysis of the problem shows us that the smallest missing number would be the element’s index, which is not equal to its element. For instance, consider array `[0, 1, 2, 6, 9, 11, 15]`. Here, the smallest missing element is 3 since 6 is present at index 3 (instead of element 3). If all elements in the array are at their right position, then the smallest missing number is equal to the array size; For instance, 6 in the case of `[0, 1, 2, 3, 4, 5]`.

 A naive solution would be to run a **linear search** on the array and return the first index, which doesn’t match its value. If no mismatch happens, then return the array size. The problem with this approach is that its worst-case time complexity is `O(n)`, where n is the size of the input. This solution also does not take advantage of the fact that the input is sorted.

 We can easily solve this problem in `O(log(n))` time by modifying the binary search algorithm. The idea is to compare the mid-index with the middle element. If both are the same, then the mismatch is in the right subarray; otherwise, it lies in the left subarray. So, we discard one half accordingly and recur for the other. 
 