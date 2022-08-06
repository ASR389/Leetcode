class Solution {
public:
    int dp[205][205];
    int cal(int i, int j, vector<vector<int>>& triangle){
        if(i==triangle.size() || j == triangle.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = triangle[i][j] + min(cal(i+1,j,triangle),cal(i+1,j+1,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return cal(0,0,triangle);
    }
};