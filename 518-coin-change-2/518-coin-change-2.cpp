class Solution {
    int dp[305][5005];
int solve(vector<int>& coins, int amount, int n){
    
    if(n==0 && amount!=0) return 0;
    if(amount == 0) return 1;
        
        if(dp[n][amount]!=-1)return dp[n][amount];
    
    if(coins[n-1]<=amount) 
        return dp[n][amount] = solve(coins,amount,n-1) + solve(coins,amount-coins[n-1],n);
    else
        return dp[n][amount] = solve(coins,amount,n-1);
}
    
public:

    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int res = solve(coins,amount,coins.size());
        return res;
    }
};