// Non-overlapping Intervals

// https://leetcode.com/problems/non-overlapping-intervals?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= intervals.length <= 10^5
    intervals[i].length == 2
    -5 * 10^4 <= starti < endi <= 5 * 10^4

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping
*/

#include<bits/stdc++.h>

using namespace std;

static bool comp(vector<int>& i1, vector<int>& i2) {
    return i1[1] < i2[1];               // sort accrding to endTime of intervals
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    
    int cnt = 0;
    int endTime = intervals[0][1];          // always a valid (non-overlapping) interval
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < endTime) {    // if overlap
            cnt++;
        }
        else {
            endTime = intervals[i][1];      // change the endTime
        }
    }
    return cnt;
}