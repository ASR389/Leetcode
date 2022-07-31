class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n+1,0);
        vector<int>output;
        for(auto i:nums){
            arr[i]++;
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]==0){
                output.push_back(i);
            }
        }
        return output;
    }
};