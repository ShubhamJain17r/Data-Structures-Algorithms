// Jump Game

// https://leetcode.com/problems/jump-game?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 10^4
    0 <= nums[i] <= 10^5
*/

#include<bits/stdc++.h>

using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;
    int i = 0;
    while (i <= maxReach) {
        if (maxReach >= nums.size() - 1)
            return true;
        maxReach = max(maxReach, i + nums[i]); // get the maximum index you can reach from that index
        i++;
    }
    return false;
}
