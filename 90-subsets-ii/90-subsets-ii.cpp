class Solution {
public:

vector<vector<int>> ans;
vector<int> temp;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
              
     int n=nums.size();
    
     sort(nums.begin(),nums.end());
    
     solve(0,nums);     
    
     return ans;
    
}

void solve(int i,vector<int>& nums) {
    
    if(i==nums.size()){ans.push_back(temp);return;}
    
    temp.push_back(nums[i]);
    solve(i+1,nums);
    temp.pop_back();
    
    int val=nums[i];
    
    while(i!=nums.size() and nums[i]==val){i++;}
    
    solve(i,nums);  
    
    
}

};