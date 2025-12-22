// Koko Eating Bananas

// https://leetcode.com/problems/koko-eating-bananas?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints : 
    1 <= piles.length <= 10^4
    piles.length <= h <= 10^9
    1 <= piles[i] <= 10^9

Important :
    Return the minimum integer k such that she can eat all the bananas within h hours.
*/

#include<bits/stdc++.h>

using namespace std;

/*
suppose eatingRate = r;
total hours = sum(for pile in piles: ceil(pile / r))
if hours <= h can be answer.

if the min hours is m then m + 1, m + 2, ...
can be the rate of eating the banana but we need to find minimum rate i.e. lower bound

piles           = [3, 6, 7, 11]
rate            = 1 , 2 , 3 , 4, 5, 6, 7, 8
corresponding hr= 27, 15, 10, 8, 8, 6, ...
h = 8,
min answer = 4.
*/

int getMaxValue(const vector<int>& piles) {
    int maxValue = INT_MIN;
    for (int pileSize : piles)
        maxValue = max(maxValue, pileSize);
    return maxValue;
}

bool canFinishWithinHours(const vector<int>& piles, int bananasPerHour, int totalHours) {
    for (int pileSize : piles) {
        totalHours -= static_cast<int>(ceil(pileSize / static_cast<double>(bananasPerHour)));
        if (totalHours < 0)
            return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = getMaxValue(piles);

    while (left <= right) {
        int midSpeed = left + ((right - left) >> 1);

        if (canFinishWithinHours(piles, midSpeed, h))
            right = midSpeed - 1;
        else
            left = midSpeed + 1;
    }
    return left;
}
