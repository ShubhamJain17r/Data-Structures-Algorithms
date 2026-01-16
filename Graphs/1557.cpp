// Minimum Number of Vertices to Reach All Nodes

// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes?envType=problem-list-v2&envId=v1la8fps

/*
Constraints:
    2 <= n <= 10^5
    1 <= edges.length <= min(10^5, n * (n - 1) / 2)
    edges[i].length == 2
    0 <= fromi, toi < n
    All pairs (fromi, toi) are distinct

Important:
    Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> indegree(n, 0);

    for (const auto &edge : edges) {
        indegree[edge[1]]++;
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            ans.push_back(i);
        }
    }

    return ans;
}