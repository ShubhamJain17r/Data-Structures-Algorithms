// Max Consecutive Ones 3

// https://leetcode.com/problems/max-consecutive-ones-iii?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.
    0 <= k <= nums.length
*/

#include<bits/stdc++.h>

using namespace std;

// store last k zero's indices and compute window size
// TC : O(n), SC : O(k)
int longestOnes(vector<int>& nums, int k) {
    queue<int> q;
    int maxLen = 0;
    int l = 0;
    int cnt = 0;
    for (int r = 0; r < nums.size(); ++r) {
        cnt += nums[r];
        if (nums[r] == 0)
            q.push(r);
        if ((r - l + 1) - cnt <= k)
            maxLen = max(maxLen, (r - l + 1));
        else {
            int last = q.front(); q.pop();
            cnt -= (last - l);
            l = last + 1;
        }
    }
    return maxLen;
}

/*
The below solution works because we only shrink when the zeroes exceeds k, until then the window is expanded. No need to skrink below our current window size.
*/

// TC : O(n) SC : O(1)
int longestOnes(vector<int>& nums, int k) {
    int maxLen = 0;
    int l = 0;
    int zeroes = 0;
    for (int r = 0; r < nums.size(); ++r) {
        if (nums[r] == 0)
            zeroes++;
        if (zeroes > k) {
            if (nums[l] == 0)
                zeroes--;
            l++;
        }
        else 
            maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}