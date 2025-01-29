/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different 
day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, 
return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {

    // Edge case: if there are less than 2 days, no profit can be made
    if (prices.size() < 2) return 0;

    // we maintain 2 variables and check in each iteration, the min price and the max profit
    int minPrice = prices[0];  // Initialize with the first price as the minimum price
    int maxProfit = 0;  // No profit at the start

    for (int i = 1; i < prices.size(); i++) {
        // If current price is less than the minimum price, update minPrice
        minPrice = min(minPrice, prices[i]);

        // Calculate the profit if we sold at the current price
        int profit = prices[i] - minPrice;

        // Update maxProfit if the current profit is greater than the previous maxProfit
        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}

int main(){

    int n;
    cin>>n;

    vector<int>arr;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int maxProfitResult = maxProfit(arr);

    cout<<"Max: "<<maxProfitResult<<endl;

    return 0;
}