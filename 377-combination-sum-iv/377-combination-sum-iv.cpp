class Solution {
public:
    int solve(vector<int>& nums, int target, int dp[]){
//         base case
        if(target < 0) return 0;
        if(target == 0) return 1;
        
        if(dp[target]!=-1) return dp[target];
        
        int ans =0;
        for(int i=0; i<nums.size(); i++){
            ans += solve(nums, target-nums[i], dp); 
            dp[target] = ans;
     }
        return dp[target];
 }  
    int combinationSum4(vector<int>& nums, int target) { 
        int dp[target+1];
        memset(dp,-1,sizeof(dp));
        
        return solve(nums, target, dp);
    }
};