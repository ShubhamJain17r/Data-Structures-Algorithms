// Capacity to Ship Packages within D days

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= days <= weights.length <= 5 * 104
    1 <= weights[i] <= 500

Important : 
    Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/

#include<bits/stdc++.h>

using namespace std;

/*
after capacity c, every capacity can be used but we need to return its lower bound.
*/

bool canFinishWithinDays(vector<int>& weights, int capacity, int days) {
    long long sum = 0;
    int daysTaken = 1;
    for (const int &weight : weights) {
        sum += weight;
        if (sum > capacity) {
            daysTaken++;
            sum = weight;
        }
    }
    return daysTaken <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = left * 2;

    while (!canFinishWithinDays(weights, right, days)) right *= 2;

    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (canFinishWithinDays(weights, mid, days)) right = mid - 1;
        else                                         left = mid + 1;
    }
    return left;
}

