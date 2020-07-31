/*
Best Time to Buy and Sell Stock with Cooldown

Solution
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]Best Time to Buy and Sell Stock with Cooldown

Solution
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/
class Solution {
    int buySell(int i,int buyorsell,vector<int>& prices,unordered_map<string,int>& um1)
    {
            if(i>=prices.size())
                    return 0;
            string key = to_string(i)+"yoyo"+to_string(buyorsell);
            
            if(um1.find(key)!=um1.end())
                    return um1[key];
            int profit = 0;
            
            if(buyorsell==0)
            {
                    int buy = buySell(i+1,1,prices,um1)-prices[i];
                    int nobuy =  buySell(i+1,0,prices,um1);
                    profit = max(buy,nobuy);
            }
            
            else
            {
                    int sell = buySell(i+2,0,prices,um1)+prices[i];
                    int nosell = buySell(i+1,1,prices,um1);
                    profit = max(sell,nosell);
            }
            um1[key] = profit;
            return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
            unordered_map<string,int> um1;
            return buySell(0,0,prices,um1);
        
    }
};