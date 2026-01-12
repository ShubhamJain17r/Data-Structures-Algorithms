// Find the Town Judge

// https://leetcode.com/problems/find-the-town-judge?envType=problem-list-v2&envId=v1la8fps

/*
Constraints:
    1 <= n <= 1000
    0 <= trust.length <= 10^4
    trust[i].length == 2
    All the pairs of trust are unique.
    ai != bi
    1 <= ai, bi <= n

Important:
    If the town judge exists, then:
        1. The town judge trusts nobody.
        2. Everybody (except for the town judge) trusts the town judge.
        3. There is exactly one person that satisfies properties 1 and 2.
        
    You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
    Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
*/

#include<bits/stdc++.h>

using namespace std;

// in_degree[judge] = n - 1, out_degree[judge] = 0

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> in_degree(n + 1, 0);
    vector<int> out_degree(n + 1, 0);

    for (const vector<int> &p : trust) {
        int from = p[0], to = p[1];
        out_degree[from]++;
        in_degree[to]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == n - 1 && out_degree[i] == 0) return i;
    }
    return -1;
}