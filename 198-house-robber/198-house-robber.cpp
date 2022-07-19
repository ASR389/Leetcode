class Solution {
public:
    int dp[405];
    int solve(vector<int>nums, int n){
        //base condition
        if(n<0) return 0;  //imp to remember as n-1 reaches here
        if(n==0) return nums[0];
        
        if(dp[n]!=-1)return dp[n];
        
        int incl = nums[n] + solve(nums,n-2);
        int excl = solve(nums,n-1);
        
        int ans = max(incl,excl);
        return dp[n] = ans;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,nums.size()-1);    
    }
};