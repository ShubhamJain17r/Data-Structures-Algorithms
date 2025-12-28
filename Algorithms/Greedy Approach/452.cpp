// Minimum Number of Arrows to Burst Balloons

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= points.length <= 10^5
    points[i].length == 2
    -2^31 <= xstart < xend <= 2^31 - 1
*/

#include<bits/stdc++.h>

using namespace std;

static bool comp(vector<int>& p1, vector<int>& p2) {
    return p1[1] < p2[1];
}

/*
if the current points are out of the desired interval, we reset the interval.
*/

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), comp);

    // for (const vector<int> &v : points) {
    //     cout<<v[0]<<"\t"<<v[1]<<endl;
    // }

    int prev = 0;
    long long intervalStart = LLONG_MIN;    // start xstart can be -2^31 and we want default to be smaller
    long long intervalEnd = LLONG_MAX;

    int arrows = 0;

    for (int curr = 0; curr < points.size(); ++curr) {
        if (intervalStart == LLONG_MIN) {
            arrows++;
            intervalStart = max(points[prev][0], points[curr][0]);
            intervalEnd = min(points[prev][1], points[curr][1]);
        }
        if (points[curr][0] > intervalEnd) {
            intervalStart = LLONG_MIN;
            intervalEnd = LLONG_MAX;
            prev = curr;
        }
        else {
            intervalStart = max(intervalStart, 1LL * points[curr][0]);
            intervalEnd = min(intervalEnd, 1LL * points[curr][1]);
        }
        if (intervalStart > intervalEnd) {
            intervalStart = LLONG_MIN;  
            intervalEnd  =  LLONG_MAX;
        }
    }
    if (intervalStart == LLONG_MIN) return arrows + 1;
    return arrows;
}

// simple code :)
// int findMinArrowShots(vector<vector<int>>& points) {
//     sort(points.begin(), points.end(), comp);

//     int arrows = 1;
//     int endTime = points[0][1];
//     for (int i = 1; i < points.size(); ++i) {
//         if (points[i][0] > endTime) {
//             arrows++;
//             endTime = points[i][1];
//         }
//     }
//     return arrows;
// }