class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currmax = 0, max = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            currmax += nums[i];
            if(max < currmax) max = currmax;
            if(currmax < 0) currmax = 0;
        }
        return max;
    }
};