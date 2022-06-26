class Solution {
public:

    int Change(vector<int>& coins, int amount ,int dp[]){
        //base case
        if(amount==0) return 0;
        
        if(dp[amount] != -1) return dp[amount];
        
        int ans=INT_MAX;
        for(int coin:coins){
                if(amount-coin>=0){
                      ans=min(ans+0LL,1LL+Change(coins,amount-coin,dp));  
                }
        }
        dp[amount]=ans;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        // dp of amounts
        int dp[10001];
        memset(dp,-1,sizeof(dp));
        int ans=Change(coins,amount,dp);
        return ans == INT_MAX ? -1 : ans;  
    }
};