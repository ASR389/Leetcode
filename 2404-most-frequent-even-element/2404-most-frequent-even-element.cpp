class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      map<int,int> ump;
        int ans=-1,temp=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0&&ump[nums[i]]>temp){
                ans=nums[i];
                temp=ump[nums[i]];
            }
            ump[nums[i]]++;
        }
        
        return ans;
    }
};