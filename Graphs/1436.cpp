// Destination City

// https://leetcode.com/problems/destination-city?envType=problem-list-v2&envId=v1la8fps

/*
Constraints:
    1 <= paths.length <= 100
    paths[i].length == 2
    1 <= cityAi.length, cityBi.length <= 10
    cityAi != cityBi
    All strings consist of lowercase and uppercase English letters and the space character
*/

#include<bits/stdc++.h>

using namespace std;

// simple search the node with no outgoing edge
string dfs(unordered_map<string, vector<string>> &graph, unordered_set<string> &visited, string &node) {
    visited.insert(node);
    for (string &nei : graph[node]) {
        if (visited.count(nei) == 0) {
            return dfs(graph, visited, nei);
        }
    }
    return node;
}
string destCity(vector<vector<string>>& paths) {
    unordered_map<string, vector<string>> graph;
    for (vector<string> &path : paths) {
        graph[path[0]].push_back(path[1]);
    }
    unordered_set<string> visited;
    string start = paths[0][0];
    return dfs(graph, visited, start);
}

// find the node with no outgoing edge
string destCity(vector<vector<string>>& paths) {
    vector<string> ch;
    for (int i = 0; i < paths.size(); i++) ch.push_back(paths[i][0]);
    for (int i = 0; i < paths.size(); i++) {
        if (count(ch.begin(),ch.end(),paths[i][1]) == 0) return paths[i][1];
    }
    return "";
}