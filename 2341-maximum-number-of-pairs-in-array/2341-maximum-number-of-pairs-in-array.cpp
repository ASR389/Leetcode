class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int>ans(2,0);
        unordered_map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
            ans[0]+=i.second/2;
            ans[1]+=i.second%2;
        }
        return ans;
    }
};