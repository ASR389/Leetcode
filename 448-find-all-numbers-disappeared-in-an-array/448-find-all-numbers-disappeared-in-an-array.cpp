class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        vector<int>a;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        
        for(int i=1; i<=nums.size(); i++){
            if(mp[i] == 0){
                a.push_back(i);
            } 
        }
        return a;
    }
};