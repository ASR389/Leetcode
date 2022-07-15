class Solution {
public:
    int dp[51][51];
    int solve(vector<int>& values, int i, int j){
        //base case
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i; k<=j-1; k++){
            int temp = solve(values, i, k) + solve(values, k+1, j) + (values[i-1]*values[k]*values[j]) ;
            ans = min(ans,temp);
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return solve(values, 1 , values.size()-1);  
    }
};