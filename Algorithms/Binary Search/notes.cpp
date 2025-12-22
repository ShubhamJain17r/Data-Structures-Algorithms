// This file contains code snippets frequently used in Binary Search Algorithm.

#include<bits/stdc++.h>

using namespace std;

/*
middle index = (l + r) / 2;
but when l and r are very large of their addition can give memory overflow for that case we use 
middle index = l + (r - l) / 2;

*/

int binary_search(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        int mid = arr[m];

        if (mid == target)  return m;
        if (mid < target)   l = m + 1;
        else                r = m - 1;
    }
    return -1;
}

int lower_bound(vector<int>& arr, int val) {
    // smallest index such that arr[idx] >= n

    int l = 0, r = arr.size() - 1;
    int lb = arr.size();
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        int mid = arr[m];

        if (mid < val)      l = m + 1;
        else {
            lb = m;
            r = m - 1;
        }
    }
    return lb;
}

int upper_bound(vector<int>& arr, int val) {
    // smallest index such that arr[idx] > n

    int l = 0, r = arr.size() - 1;
    int ub = arr.size();
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        int mid = arr[m];

        if (mid <= val)      l = m + 1;
        else {
            ub = m;
            r = m - 1;
        }
    }
    return ub;
}