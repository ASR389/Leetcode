class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]] > 1){
                ans =  nums[i];
            }
        }
       return ans; 
    }
};

// https://leetcode.com/problems/find-the-duplicate-number/discuss/1892872/C%2B%2B-oror-Algorithm-oror-4-Approaches-oror-Binary-Search-oror-Brute-Force-oror-cnt-array-oror-map