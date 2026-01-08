// Find Ceenter of Star Graph

// https://leetcode.com/problems/find-center-of-star-graph?envType=problem-list-v2&envId=v1la8fps

/*
Constraints:
    3 <= n <= 10^5
    edges.length == n - 1
    edges[i].length == 2
    1 <= ui, vi <= n
    ui != vi
    The given edges represent a valid star graph

Important:
    There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node
*/

#include<bits/stdc++.h>

using namespace std;

// This code works because the centre node is present in every edge and other nodes appear only once.
int findCenter(vector<vector<int>>& edges) {
    int node1 = edges[0][0];
    int node2 = edges[0][1];

    if (edges[1][0] == node1 || edges[1][1] == node1) return node1;
    return node2;
}