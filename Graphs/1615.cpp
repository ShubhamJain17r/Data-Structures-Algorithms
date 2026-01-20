// Maximal Network Rank

// https://leetcode.com/problems/maximal-network-rank?envType=problem-list-v2&envId=v1la8fps

/*
Constraints:
    2 <= n <= 100
    0 <= roads.length <= n * (n - 1) / 2
    roads[i].length == 2
    0 <= ai, bi <= n-1
    ai != bi
    Each pair of cities has at most one road connecting them
*/

#include<bits/stdc++.h>

using namespace std;

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<int> degree(n, 0);
    vector<vector<bool>> connected(n, vector<bool>(n, false));

    // Count degrees and mark connections
    for (auto& r : roads) {
        int u = r[0], v = r[1];
        degree[u]++;
        degree[v]++;
        connected[u][v] = true;
        connected[v][u] = true;
    }

    int maxRank = 0;

    // Check all city pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rank = degree[i] + degree[j];
            if (connected[i][j]) rank--;
            maxRank = max(maxRank, rank);
        }
    }
    return maxRank;
}
