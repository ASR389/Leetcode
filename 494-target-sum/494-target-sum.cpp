class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int diff = target;  //just for understanding i change the names
     // the problem will be same as count the # subset in a given diff
     // we will sove this like previos problem
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum+=nums[i];
        
        if((sum+diff)%2 !=0 || target > sum) return 0;
        
        int s1 = abs((diff+sum)/2);   //for -ve number remember for abs
        
        //now count subset sum  means count s1 possibility
        int dp[n+1][s1+1];
        
        for(int i=0;i<s1+1;i++) dp[0][i] = 0;
        for(int i=0;i<n+1;i++) dp[i][0] = 1;
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<s1+1;j++){
                if(nums[i-1]<=j)
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][s1];
        
    }
};