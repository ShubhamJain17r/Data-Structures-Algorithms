// Min Stack

// https://leetcode.com/problems/min-stack?envType=problem-list-v2&envId=v1lwf7tc

/*
Constraints:
    -2^31 <= val <= 2^31 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 104 calls will be made to push, pop, top, and getMin

Important:
    Implement the MinStack class:
        MinStack() initializes the stack object.
        void push(int val) pushes the element val onto the stack.
        void pop() removes the element on the top of the stack.
        int top() gets the top element of the stack.
        int getMin() retrieves the minimum element in the stack.
    You must implement a solution with O(1) time complexity for each function.
*/

#include<bits/stdc++.h>

using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minStack;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (minStack.empty() || minStack.top() >= val)          // is curr element smaller
            minStack.push(val);

        /*
        ------------ Second Approach -----------------------------------
        if (minStack.empty()) minStack.push(val);
        else                  minStack.push(min, minStack.top(), val);

        it stores the minimum upto index i, its size is same as st stack
        */
    }
    
    void pop() {
        if (minStack.top() == st.top())
            minStack.pop();
        st.pop();

        /*
        if using second approach just pop from both stacks
        */
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};