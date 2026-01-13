// Number of Recent Calls

// https://leetcode.com/problems/number-of-recent-calls?envType=problem-list-v2&envId=v1lwf7tc

/*
Constraints:
    1 <= t <= 10^9
    Each test case will call ping with strictly increasing values of t.
    At most 10^4 calls will be made to ping
*/

#include<bits/stdc++.h>

using namespace std;

class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) q.pop();
        return q.size();
    }
};