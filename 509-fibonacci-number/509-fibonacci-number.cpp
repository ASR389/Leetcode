class Solution {
public:
    int solve(int n, vector<int>&dp){
        //base case
        dp[0] = 0;
        dp[1] = 1;
  //tabulation method          
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
        vector<int>dp(n+1);
        
        if(n == 0) return 0; //yeh dhyan rakh lena ki 0 ho toh reutrn 0 kr de
        int ans = solve(n,dp);
        
        return ans;
        
    }
};