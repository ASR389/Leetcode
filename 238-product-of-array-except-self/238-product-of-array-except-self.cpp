class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>lr(nums.size());
        vector<int>rl(nums.size());
        vector<int>ans(nums.size());
        
        int temp =1;
        for(int i=0; i<nums.size(); i++){
            temp = temp * nums[i];
            lr[i] = temp;
        }
        
        
        temp = 1;
        for(int i=nums.size()-1; i>=0; i--){
            temp = temp * nums[i];
            rl[i] = temp;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                ans[i] = rl[1];
            }
           else if(i==nums.size()-1){
                ans[i] = lr[nums.size()-2];
            }
            else{
            int tempa = lr[i-1]*rl[i+1];
            ans[i] = tempa;
            }
        }
        
        return ans;
    }
};