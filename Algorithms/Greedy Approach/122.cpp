// Best time To Buy and Sell Stock 2

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= prices.length <= 3 * 10^4
    0 <= prices[i] <= 10^4

Important : 
    On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
    Find and return the maximum profit you can achieve.
*/

#include<bits/stdc++.h>

using namespace std;

/*
This solution works because we can sell and buy on the same day. eg
prices    =     [7, 1, 5, 100, 6, 4]
maxProfit =         0, 4, 99, 99, 99
Buy       :         .  .     
sell      :            .   .            sell first then buy
{99 + 6 - 100 < 99 }

*/

int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        int netDiff = prices[i] - prices[i - 1];
        maxProfit = max(maxProfit, maxProfit + netDiff);
    }
    return maxProfit;
}