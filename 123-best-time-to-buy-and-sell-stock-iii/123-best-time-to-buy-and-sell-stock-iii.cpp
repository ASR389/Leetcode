class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minSofar1 = INT_MAX;
        int minSofar2 = INT_MAX;
        
        int profit1 = 0;
        int profit2 = 0;
        
        for(int i=0; i<prices.size(); i++){
            minSofar1 = min(minSofar1,prices[i]);
            profit1 = max(profit1,prices[i]-minSofar1);
            minSofar2 = min(minSofar2,prices[i]-profit1);
            profit2 = max(profit2,prices[i]-minSofar2);
        }
        return profit2 ;
    }
};