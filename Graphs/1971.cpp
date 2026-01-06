// Find if Pah exists in Graph

// https://leetcode.com/problems/find-if-path-exists-in-graph?envType=problem-list-v2&envId=v1la8fps

/*
Constraints:
    1 <= n <= 2 * 10^5
    0 <= edges.length <= 2 * 10^5
    edges[i].length == 2
    0 <= ui, vi <= n - 1
    ui != vi
    0 <= source, destination <= n - 1
    There are no duplicate edges.
    There are no self edges
*/

#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& graph, int src, int dest, vector<bool>& visited) {
    if (src == dest)                    // found path from src to dest
        return true;
    visited[src] = true;
    for (const int &nei : graph[src]) {
        if (!visited[nei]) {
            if (dfs(graph, nei, dest, visited))
                return true;
        }
    }
    return false;                       // didn't find path from curr src to dest
}
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<bool> visited(n, false);
    vector<vector<int>> graph(n);              
    for (vector<int> &edge : edges) {       // create graph from edges
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    return dfs(graph, source, destination, visited);

}