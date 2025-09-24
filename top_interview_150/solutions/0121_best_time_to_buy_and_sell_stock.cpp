/*
 * LeetCode 121. Best Time to Buy and Sell Stock
 * Language: C++
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Approach:
 *   Track the minimum price seen so far while iterating. 
 *   At each day, compute the profit if sold today, and update the maximum profit. 
 *   This ensures we find the best single buy-sell transaction.
 */

 #include<vector>
 using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentMin=INT_MAX;
        int currentMaxProfit=0;
        for(int x:prices){
            currentMaxProfit=max(currentMaxProfit,x-currentMin);
            currentMin=min(currentMin,x);
        }
        return currentMaxProfit;
    }
};