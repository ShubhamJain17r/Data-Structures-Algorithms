// Implement Queue using Stacks

// https://leetcode.com/problems/implement-queue-using-stacks?envType=problem-list-v2&envId=v1lwf7tc

/*
Constraints:
    1 <= x <= 9
    At most 100 calls will be made to push, pop, peek, and empty.
    All the calls to pop and peek are valid
*/

#include<bits/stdc++.h>

using namespace std;

/*
if s2 is empty then we shift the elements to it for popping and finding top.

push doesn't require checking s2 as we dont need s1 for pop or top functions
*/

class MyQueue {
private:
    stack<int> s1;      // stack
    stack<int> s2;      // pseudo queue
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int first = s2.top();
        s2.pop();
        return first;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};