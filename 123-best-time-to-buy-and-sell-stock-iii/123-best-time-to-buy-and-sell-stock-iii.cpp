
/*
Suppose you make some profit p1 by doing your first transaction in the stock market. Now you are excited to purchase another stock to earn more profit. Suppose the price of the second stock you aim to buy is x. Now, for you, the net effective price that you are spending from your pocket for this stock will be x-p1, because you already have p1 bucks in your hand. Now, if you sell the second stock at price y your net profit p2 will be p2 = y - (x-p1). You have to do nothing but maximize this profit p2. Here's the code:
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy1    = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2    = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};