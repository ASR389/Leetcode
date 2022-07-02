class Solution {
public:
    bool solve(vector<int> &nums, int &sum, int currSum, int i, vector<vector<int>> &dp)
{
    if(2 * currSum == sum)
        return true;
    
    if(2 * currSum > sum ||  i == nums.size())
        return false;
    
    if(dp[i][currSum] != -1)
        return dp[i][currSum];
    
    return dp[i][currSum] = solve(nums, sum, currSum, i + 1, dp) || solve(nums, sum, currSum + nums[i], i + 1, dp);      }
    
    bool canPartition(vector<int>& nums) {
         int sum = 0;
         for(auto &i : nums)
           sum += i;
    
        vector<vector<int>> dp(nums.size() + 1, vector<int> (20001, -1));
        return solve(nums, sum, 0, 0, dp);
}


};