// Valid Perfect Square

// https://leetcode.com/problems/valid-perfect-square?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints : 
    1 <= num <= 2^31 - 1

Important : 
    true if num is a perfect square.
    You must not use any built-in library function, such as sqrt.
*/

#include<bits/stdc++.h>

using namespace std;

bool isPerfectSquare(int num) {
    if (num == 1)   return true;
    int l = 1, r = num / 2;
    while (l <= r) {
        int m = l + ((r - l) >> 2);
        // cout<<m<<endl;
        double target = num / (double)m;
        // cout<<target<<endl<<"---"<<endl;
        if (m == target)        return true;
        else if (m < target)    l = m + 1;
        else                    r = m - 1;
    }
    return false;
}

int main() {
    // int n = 100000000;
    for (int i = 1; i < INT_MAX; ++i) {
        bool ips = isPerfectSquare(i);
        int root = (int)sqrt(i);
        bool actual = (root * root == i);
        if (ips != actual) {
            cout<<"Failed at "<<i<<" expected "<<actual<<" root : "<<root<<endl;
        }
    }
    // int i = 1601;
    // bool ips = isPerfectSquare(i);
    // int root = (int)sqrt(i);
    // bool actual = (root * root == i);
    // if (ips != actual) {
    //     cout<<"Failed at "<<i<<" expected "<<actual<<" root : "<<root<<endl;
    // }
    cout<<"EOP"<<endl;
}