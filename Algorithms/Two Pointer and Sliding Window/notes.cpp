#include<bits/stdc++.h>

using namespace std;

int fixedWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0;
    int windowSum = 0;
    int ans = INT_MIN;  // or 0 depending on problem

    for (int r = 0; r < n; r++) {
        windowSum += nums[r];          // add right element

        // when window size becomes exactly k
        if (r - l + 1 == k) {
            ans = max(ans, windowSum); // update answer

            windowSum -= nums[l];      // remove left element
            l++;                       // slide window
        }
    }
    return ans;
}

int variableWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0;
    long long windowSum = 0;
    int ans = 0;

    for (int r = 0; r < n; r++) {
        windowSum += nums[r];     // expand window

        while (windowSum > k) {  // shrink until valid
            windowSum -= nums[l];
            l++;
        }

        ans = max(ans, r - l + 1); // update answer
    }
    return ans;
}

// No of substrings type problems.

int atMostK(vector<int>& nums, int k) {
    int l = 0;
    long long sum = 0;
    int count = 0;

    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];

        while (sum > k) {
            sum -= nums[l];
            l++;
        }

        // all subarrays ending at r with sum <= k
        count += (r - l + 1);
    }
    return count;
}
int subarraySumExactlyK(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}
