// Two Sum 2

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints :
    2 <= numbers.length <= 3 * 10^4
    -1000 <= numbers[i] <= 1000
    numbers is sorted in non-decreasing order.
    -1000 <= target <= 1000
    The tests are generated such that there is exactly one solution.

Important : 
    Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
    The tests are generated such that there is exactly one solution. You may not use the same element twice.
    Your solution must use only constant extra space.
*/

#include<bits/stdc++.h>

using namespace std;

/*
Since array is sorted we can maintain two pointers l and r to track first and last element of range, l < r.
if arr[l] + arr[r] == target return {l + 1, r + 1};
if sum < target, we can increase sum by increasing index l
else decrease r;
*/

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0,  r = n - 1;
    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) return {l + 1, r + 1};
        if (sum < target) {
            l++;
            while (l < r && nums[l] == nums[l - 1]) l++;
        }
        else {
            r--;
            while (l < r && nums[r] == nums[r + 1]) r--;
        }
    }
    return {-1, -1};
}
