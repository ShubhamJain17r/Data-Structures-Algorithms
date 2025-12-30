// Matchsticks to Square

// https://leetcode.com/problems/matchsticks-to-square?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= matchsticks.length <= 15
    1 <= matchsticks[i] <= 10^8
*/

#include<bits/stdc++.h>

using namespace std;

bool makesquareHelper(vector<int>& matchsticks, int idx, vector<int> &square, int target) {
    if (idx < 0) {          // tarversed whole matchsticks
        return true;
    }

    int s = matchsticks[idx];
    for (int i = 0; i < 4; ++i) {       // on which side we should add that matchstick
        if (square[i] + s > target) continue;   // cant add this match stick

        bool skip = false;
        for (int j = 0; j < i && !skip; ++j)    // if this match aready added to other side before, reduces symmetric cases
            if (square[i] == square[j]) skip = true;

        if (skip) continue;

        square[i] = square[i] + s;
        if (makesquareHelper(matchsticks, idx - 1, square, target)) 
            return true;
        square[i] = square[i] - s;

        if (square[i] == 0) break;          // tried every stick on empty side and failed.
    }
    return false;
}

bool makesquare(vector<int>& matchsticks) {
    int n = matchsticks.size();
    if (n < 4) return false;            // not enough matchsticks

    int sum = 0;
    for (const int &val : matchsticks)
        sum += val;
    
    if (sum % 4 != 0) return false;     // can form square
    int target = sum / 4;

    for (const int &val : matchsticks)
        if (val > target) return false;         // stick larger than side

    sort(matchsticks.begin(), matchsticks.end());

    vector<int> square(4, 0);                   // sides of square
    return makesquareHelper(matchsticks, n - 1, square, target);    // start form back 
}