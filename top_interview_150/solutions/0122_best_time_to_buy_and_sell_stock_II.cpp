/*
 * LeetCode 122. Best Time to Buy and Sell Stock II
 * Language: C++
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Approach:
 *   Since we can trade unlimited times, the maximum profit is the sum of all
 *   positive price increases. Whenever today's price is higher than yesterday's,
 *   we "take" that profit. This is equivalent to buying at every local minimum
 *   and selling at every local maximum.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int totalProfit = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }
        return totalProfit;
    }
};
