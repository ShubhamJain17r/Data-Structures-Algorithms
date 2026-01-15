// Number of Students Unable to Eat Lunch

// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch?envType=problem-list-v2&envId=v1lwf7tc

/*
Constraints:
    1 <= students.length, sandwiches.length <= 100
    students.length == sandwiches.length
    sandwiches[i] is 0 or 1.
    students[i] is 0 or 1
*/

#include<bits/stdc++.h>

using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int n = students.size();
    
    int idx = 0;            // curr sandwich
    queue<int> q;

    for (int &student : students)
        q.push(student);

    while (idx != n) {
        if (sandwiches[idx] == q.front()) {         // take your lunch and leave
            q.pop();
            idx++;
            continue;
        }
        int cnt = 0;
        while (cnt <= q.size() && q.front() != sandwiches[idx]) {   // move to the back of the queue
            int x = q.front();
            q.pop();
            q.push(x);
            cnt++;
        }
        if (cnt > q.size()) return q.size();                        // whole queue traverse but didn't found appropriate sandwich
    }

    return 0;
}