// Remove Duplicates from Sorted Array

// https://leetcode.com/problems/remove-duplicates-from-sorted-array?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 3 * 10^4
    -100 <= nums[i] <= 100
    nums is sorted in non-decreasing order.
*/

#include<bits/stdc++.h>

using namespace std;

/*
ptr k points the curr inserting index, we always app element at index 0 as array is never empty
*/

int removeDuplicates(vector<int>& nums) {
    int k = 0;
    for (int i = 0; i < nums.size(); ++i)
        if (i == 0 || nums[i] != nums[i - 1])
            nums[k++] = nums[i];
    return k;
}