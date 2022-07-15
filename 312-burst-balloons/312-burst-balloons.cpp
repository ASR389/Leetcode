class Solution {
public:
    int dp[305][305];
    int solve(vector<int>&nums, int i, int j){
        //base case
        if(i>=j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int maxCoin = INT_MIN;
        for(int k = i; k<=j-1; k++){
            int temp = solve(nums,i,k) + solve(nums,k+1,j) + (nums[i - 1] * nums[k] * nums[j]);
            maxCoin = max(maxCoin,temp);
        }
        return dp[i][j] = maxCoin;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        return solve(nums,1,nums.size()-1);
        
    }
};