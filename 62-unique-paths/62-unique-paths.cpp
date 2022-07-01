class Solution {
public:
        int solve(int m,int n,int dp[][101]){
        
        if(n==1&&m==1) return 1;
        
        if(n<1||m<1) return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        int temp1=0,temp2=0;
            
        if(n>0)
            temp1=solve(m,n-1,dp);
        if(m>0)
            temp2=solve(m-1,n,dp);
            
        dp[m][n-1]=temp1;
        dp[m-1][n]=temp2;
            
        return dp[m][n] = temp1+temp2;
    }
    int uniquePaths(int m, int n) {
        int dp[101][101];
        memset(dp,-1,sizeof(dp));
        return solve(m,n,dp);
    }
};