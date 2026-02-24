#include "Student.h"

//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n:
//nums1 has length m + n
//The first m values in nums1 are real elements
//The last n values in nums1 are placeholders (0)
//nums2 has length n
//Goal: Merge nums2 into nums1 so that nums1 becomes one sorted array.
//Return: Nothing (modify nums1 in-place).

//Example:
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Input: nums1 = [1,2,3,4,0,0], m = 4, nums2 = [5,6], n = 2
//Output: nums1 = [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
 // TODO: implement
    int temp;
    for(int i = m; i < m+n; i++){
        nums1[i] = nums2[(i - m) % nums2Size];
    }
    for(int i = 0; i < nums1Size; i++){
        for(int j = i + 1; j <nums1Size; j++){
            if(nums1[i] > nums1[j]){
                temp = nums1[i];
                nums1[i] = nums1[j];
                nums1[j] = temp;
            }
        }
    }

}
