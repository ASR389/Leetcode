class Solution {
public:
    int dp[1005][1005];
    int solve(vector<int>& satisfaction, int index, int time){
        //BC
        if(index >= satisfaction.size()) return 0;
        
        if(dp[index][time] != -1) return dp[index][time];
        
        int include = satisfaction[index]* (time+1) + solve(satisfaction,index+1,time+1);
        int exclude = solve(satisfaction,index+1,time);
        
        return dp[index][time] = max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        memset(dp,-1,sizeof(dp));
        return solve(satisfaction,0,0);
    }
};