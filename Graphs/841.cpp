// Rooms and Keys

// https://leetcode.com/problems/keys-and-rooms?envType=problem-list-v2&envId=v1la8fps

/*
Constraints:
    n == rooms.length
    2 <= n <= 1000
    0 <= rooms[i].length <= 1000
    1 <= sum(rooms[i].length) <= 3000
    0 <= rooms[i][j] < n
    All the values of rooms[i] are unique
*/

#include<bits/stdc++.h>

using namespace std;

/*
visit a room, take the keys of non visited rooms and traverse.
at end if any room remains empty return false;
*/

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int room = q.front(); q.pop();
        for (const int &key : rooms[room]) {
            if (!visited[key]) {
                q.push(key);
                visited[key] = true;
            }
        }
    }

    for (int room = 0; room < n; ++room) {
        if (visited[room] == false) return false;
    }

    return true;
}