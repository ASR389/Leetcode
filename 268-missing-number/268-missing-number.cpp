class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int i=0,sum=0;
    while(i<nums.size()){
       sum+=nums[i];
        i++;
    }
    int ans=((nums.size()*(nums.size()+1))/2)-sum;
    return ans;
}    
};