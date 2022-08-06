class Solution {
public:
    int dp[205][205];
    int solve(int m,int n,vector<vector<int>>&grid){
        //base case
        if(m==grid.size()-1 and n==grid[0].size()-1) return grid[m][n];
        
        if(m == grid.size() || n == grid[0].size()) return INT_MAX;
		
		// dp->memorization
        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n]=grid[m][n] + min(solve(m+1,n,grid),solve(m,n+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        
        return solve(0,0,grid);
    }
};