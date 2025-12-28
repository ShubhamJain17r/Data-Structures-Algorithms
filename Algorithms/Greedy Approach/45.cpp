// Jump Game 2

// https://leetcode.com/problems/jump-game-ii?envType=problem-list-v2&envId=vyrqwl9s

/* 
Constraints:
    1 <= nums.length <= 10^4
    0 <= nums[i] <= 1000
    It's guaranteed that you can reach nums[n - 1].

Important : 
    Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:
    0 <= j <= nums[i] and
    i + j < n
    Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1
*/

#include<bits/stdc++.h>

using namespace std;

/*
suppose from a section where can we jump to maximum index

nums = [1 2 4 1 3 1 0 2 1 1 1 4 1 1 1 1]
from index 0 i can jump to maximum index 1, my search space is [1,1]
in search space [1,1] i can reach upto index 3, my search space is [2,3]
in search space [2,3] i can reach upto index 6, my search space is [4,6]. ans so on
*/

int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;

    int l = 0;
    int maxReach = nums[0];
    int jumps = 1;

    if (maxReach >= n - 1) return 1;        // if we can reach

    while (l < n - 1) {
        int mr = maxReach;
        for (int r = l + 1; r <= mr; ++r) {         // search space
            maxReach = max(maxReach, r + nums[r]);
            if (maxReach >= n - 1)
                return jumps + 1;
        }
        // cout<<maxReach<<" ";
        l = mr;
        jumps++;
        // cout<<jumps<<"\n";
    }
    return jumps;
}