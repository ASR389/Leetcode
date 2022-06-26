class Solution {
public:
    int solve(vector<int>&nums, int n, int dp[]){
        if(n<0) return 0;
        if(n == 0) return nums[0];
        
        if(dp[n] !=-1) return dp[n];
        
        long long incl = solve(nums, n-2, dp)+nums[n];
        long long exclu = solve(nums , n-1, dp);
        
        dp[n] = max(incl , exclu);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int dp[1001];
        memset(dp,-1,sizeof(dp));
        
        int n = nums.size();
        int ans = solve(nums,n-1, dp);
        return ans;
        
    }
};