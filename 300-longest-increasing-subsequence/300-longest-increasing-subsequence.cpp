class Solution {
private:
    vector<int> dp;
public:
    int lis(int i, vector<int> &nums){
        int ans = 1;
        if(dp[i]) return dp[i];
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                ans = max(ans, lis(j, nums) + 1);
            }
        }
        return dp[i] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(2501, 0);
        int ans = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(dp[i]){
                ans = max(ans, dp[i]);
            }
            else{
                ans = max(ans, lis(i, nums));
            }
        }
        return ans;
    }
};