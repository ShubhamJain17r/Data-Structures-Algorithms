// Majority Element

// https://leetcode.com/problems/majority-element?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    n == nums.length
    1 <= n <= 5 * 10^4
    -10^9 <= nums[i] <= 10^9
    The input is generated such that a majority element will exist in the array.
*/

#include<bits/stdc++.h>

using namespace std;

int countInRange(vector<int>& nums, int num, int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++)
        if (nums[i] == num) count++;
    return count;
}

int majorityHelper(vector<int>& nums, int l, int r) {
    if (l == r)
        return nums[l];

    int mid = l + (r - l) / 2;

    int leftMajor = majorityHelper(nums, l, mid);
    int rightMajor = majorityHelper(nums, mid + 1, r);

    if (leftMajor == rightMajor)
        return leftMajor;

    int leftCount = countInRange(nums, leftMajor, l, r);
    int rightCount = countInRange(nums, rightMajor, l, r);

    return leftCount > rightCount ? leftMajor : rightMajor;
}
// TC : O(n logn), SC : O(logn)
int majorityElement(vector<int>& nums) {
    return majorityHelper(nums, 0, nums.size() - 1);
}

/*
maintain count of max freq element if curr element != max freq element
reduce its count. if cnt == 0, change the max freq element. 
*/
// TC : O(n), SC : O(1)
// int majorityElement(vector<int>& nums) {
//     int n = nums.size();
//     if (n == 1) return nums[0];

//     int maxFreqElement = nums[0];
//     int cnt = 1;
//     for (int i = 1; i < n; ++i) {
//         if (nums[i] == maxFreqElement) {
//             cnt++;
//             if (cnt > (n / 2))
//                 return maxFreqElement;
//         }
//         else {
//             cnt--;
//             if (cnt == 0) {
//                 maxFreqElement = nums[i];
//                 cnt = 1;
//             }
//         }
//     }
//     return maxFreqElement;
// }