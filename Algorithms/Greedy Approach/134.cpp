// Gas Station

// https://leetcode.com/problems/gas-station?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    n == gas.length == cost.length
    1 <= n <= 10^5
    0 <= gas[i], cost[i] <= 10^4
    The input is generated such that the answer is unique.
*/


#include<bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int total = 0;
    int tank = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        int gain = gas[i] - cost[i];
        total += gain;
        tank += gain;
        if (tank < 0) {             // cannot start at this index
            start = i + 1;
            tank = 0;
        }
    }
    return total < 0 ? -1 : start;  // returns -1 if total cost is greater than gas startions combined
}