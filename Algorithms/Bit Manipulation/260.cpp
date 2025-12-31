// Single Number 3

// https://leetcode.com/problems/single-number-iii?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    2 <= nums.length <= 3 * 10^4
    -2^31 <= nums[i] <= 2^31 - 1
    Each integer in nums will appear twice, only two integers will appear once.
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int XOR = 0;
    for (const int &val : nums)
        XOR ^= val;                 // Xor of all numbers, duplicates cancel out

    // XOR = a ^ b                  // a and b are the two single numbers

    int bit = 1;
    while ((bit & XOR) == 0)        // get first changing bit
        bit <<= 1;
        
    // since a != b, by getting the first changing bit we can section the numbers into two buckets
    
    int one = 0, two = 0;
    for (const int &val : nums) {
        if ((val & bit) == 0)
            one ^= val;
        else
            two ^= val;
    }
    return {one, two};
}