class Solution {
public:
    int dp[205][205];
    int solve(int m,int n,vector<vector<int>>&grid){
        //base case
        if(m==0 and n==0) return grid[m][n];
		
		// dp->memorization
        if(dp[m][n]!=-1) return dp[m][n];
		
        int a = INT_MAX;
        if(m>0) 
            a = grid[m][n]+solve(m-1,n,grid);
        
        int b = INT_MAX;
        if(n>0) 
            b = grid[m][n]+solve(m,n-1,grid);
        
        return dp[m][n]=min((a),(b));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        
        return solve(m,n,grid);
    }
};