class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>um;
        int ans;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        int temp = 0;
        for(int i=0; i<100000; i++){
            if(um[i] > temp){
                temp = um[i];
                ans = i;
            }
        }
        return ans;
    }
};