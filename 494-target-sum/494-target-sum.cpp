class Solution {
public:
    void solve(vector<int>& nums, int target, int i, int &count, int sum){
        if(i == nums.size()){
            if(target == sum){
                count++;
            }
            return;
        }
        
        int curr = nums[i];
        
        solve(nums, target, i+1, count, sum+curr);
        solve(nums, target, i+1, count, sum-curr);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        
        int index = 0;
        int count = 0;
        int sum = 0;
        solve(nums, target, index, count, sum);
        return count;
    }
};