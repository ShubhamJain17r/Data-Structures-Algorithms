// Magnetic Force Between Two Balls

// https://leetcode.com/problems/magnetic-force-between-two-balls?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints : 
    n == position.length
    2 <= n <= 10^5
    1 <= position[i] <= 10^9
    2 <= m <= position.length
    All integers in position are distinct.
*/

#include<bits/stdc++.h>

using namespace std;

/*
if distance d is possible then distances less than d are also possibel so discard them to find maximim dist.
*/

bool distPossible(vector<int> &position, int balls, int dist) {
    int last = position[0];
    int cnt = 1;
    for (int i = 1; i < position.size(); ++i) {
        if (position[i] - last >= dist) {
            cnt++;
            last = position[i];
            if (cnt == balls) return true;
        }
    }
    return false;
}

int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int l = 1, r = position.back() - position[0];
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (distPossible(position, m, mid)) l = mid + 1;
        else                                r = mid - 1;
    }
    return r;
}