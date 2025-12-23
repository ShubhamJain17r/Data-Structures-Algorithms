// Container with Most Water

// https://leetcode.com/problems/container-with-most-water?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    n == height.length
    2 <= n <= 10^5
    0 <= height[i] <= 10^4
*/

#include<bits/stdc++.h>

using namespace std;

/*
Area between two blocks = min(height1, height2) * (idx2 - idx1);
we can maintain two pointers to get indices as well as helps to iterate the array in linear time.
we Move the iterator according to min height as it only dictates the capacity to be filled.
*/

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int maxA = INT_MIN;
    while (l < r) {
        int water = (r - l) * min(height[l], height[r]);
        maxA = max(maxA, water);
        if (height[l] < height[r])
            l++;
        else 
            r--;
    }
    return maxA;
}