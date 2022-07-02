int dp[201][100001];
class Solution {
public:
    bool solve(vector<int>& nums,int sum, int n){
        if(sum == 0) return true;
        if(n == 0 && sum > 0) return false;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        if(nums[n-1] <= sum){
            int incl = solve(nums,sum-nums[n-1],n-1);
            int excl = solve(nums,sum,n-1);
            return dp[n][sum]=(incl || excl);
        }
        else{
            return dp[n][sum]=solve(nums,sum,n-1);
        }
        // return 0;     
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum =0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        
        int n = nums.size();
        int target = sum/2;
        return solve(nums,target,n);
    }
};