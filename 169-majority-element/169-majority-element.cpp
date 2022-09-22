class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x:nums){
            m[x]++;
        }
        int ans = 0, f = 0;
        for(auto x:m){
            if(ans == 0){
                ans = x.first;
                f = x.second;
            }
            else if(f<x.second){
                ans = x.first;
                f = x.second;
            }
        }
        return ans;
    }
};