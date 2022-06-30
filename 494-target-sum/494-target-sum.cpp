class Solution {
    
    int helper( int * arr , int n , int target){
        
        // base case
      
        if( n == 1) {
            
            if( arr[0] == 0 && target == 0) return 2;
            if(arr[0] == abs(target)) return 1;
            else return 0;
        }
        
        
        return helper( arr+1 , n-1 , target - arr[0]) + helper( arr+1 , n-1 , target + arr[0]);
        
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int arr[nums.size()];
        
       for(int i = 0 ; i < nums.size() ; i++){
           
           arr[i] = nums[i];
       }
        
        return helper( arr , nums.size() , target);
        
    }
};