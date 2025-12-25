// Interval List Intersections

// https://leetcode.com/problems/interval-list-intersections/description/?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    0 <= firstList.length, secondList.length <= 1000
    firstList.length + secondList.length >= 1
    0 <= start[i] < end[i] <= 10^9
    end[i] < start[i+1]
    0 <= start[j] < end[j] <= 10^9 
    end[j] < start[j+1]
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    int n = firstList.size();
    int m = secondList.size();
    if (n == 0 || m == 0) return {};

    vector<vector<int>> interSections;
    int l = 0, r = 0;
    while (l < n && r < m) {
        int s1 = firstList[l][0];
        int e1 = firstList[l][1];
        int s2 = secondList[r][0];
        int e2 = secondList[r][1];

        int maxS = max(s1, s2);
        int minE = min(e1, e2);

        if (maxS <= minE)
            interSections.push_back({maxS, minE});
        if (e2 > e1)
            l++;
        else
            r++;
    }
    return interSections;
}