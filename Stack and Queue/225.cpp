// Implement Stack using Queue

// https://leetcode.com/problems/implement-stack-using-queues?envType=problem-list-v2&envId=v1lwf7tc

/*
Constraints:
    1 <= x <= 9
    At most 100 calls will be made to push, pop, top, and empty.
    All the calls to pop and top are valid
*/

#include<bits/stdc++.h>

using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {}
        
    void push(int x) {
        int sz = q.size();
        q.push(x);
        for (int i = 0; i < sz; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int last = q.front(); q.pop();
        return last;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};