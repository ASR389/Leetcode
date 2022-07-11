class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int res = 0;
        int min_diff = INT_MAX;
        
        for(int i=0; i<n-2; i++)
        {
            int lo = i+1;
            int hi = n-1;
            
            while(lo < hi)
            {
                int sum = nums[i] + nums[lo] + nums[hi];
                if(abs(target - sum) < min_diff)
                {
                    min_diff = abs(target - sum);
                    res = sum; 
                }
                else if(sum > target)
                {
                    hi--;
                }
                else
                {
                    lo++;
                }
            }
        }
        return res;
    }
};