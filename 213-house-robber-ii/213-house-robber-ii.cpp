class Solution {
public:
    int dp[10005], t[10005];
    int solve(vector<int>sol,int n){
        //base case
        if(n<0) return 0;
        if(n==0) return sol[0];
        
        if(dp[n]!=-1) return dp[n];
        
        int incl = sol[n] + solve(sol,n-2);
        int excl = solve(sol,n-1);
        
        int ans = max(incl,excl);
        return dp[n] = ans;
    }
    int solve2(vector<int>sol,int n){
        //base case
        if(n<0) return 0;
        if(n==0) return sol[0];
        
        if(t[n]!=-1) return t[n];
        
        int incl = sol[n] + solve2(sol,n-2);
        int excl = solve2(sol,n-1);
        
        int ans = max(incl,excl);
        return t[n] = ans;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        memset(t,-1,sizeof(t));
        
        int n = nums.size();
        if(n == 1)return nums[0];
        // if(n == 2)return max(nums[0],nums[1]);
        // if(n == 3)return max(nums[0],max(nums[1],nums[2]));
        
        
        vector<int> first;
        vector<int> second;
        
        for(int i =0; i<n-1; i++){
            first.push_back(nums[i]);
          
        }
        for(int j =1; j<n; j++){
            second.push_back(nums[j]);   
        }
        int ans1 = solve(first,first.size()-1);
        int ans2 = solve2(second,second.size()-1);
    
        return max(ans1,ans2);

    }
};