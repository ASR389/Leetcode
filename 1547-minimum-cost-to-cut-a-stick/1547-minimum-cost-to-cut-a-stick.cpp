class Solution {
public:
  // any rod starts from start idx , ends to end_idx , 
    
    // then no. of possible cuts , start+1 - end-1
    int func(int start , int end , vector<vector<int>> &dp , vector<int> &cut)
    {
        if(abs(start-end)<=1)
        {
            // as start and end is not included in the cut part 
            // if diff<=1 , then it means 
            // there us only start & end present , so no cut possible 
            // return 0
            return 0;
        }
        
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        
        int min_cost=INT_MAX;
        
        for(int i=start+1 ;i<=end-1 ;i++)
        {
            int curr_cost= (cut[end]-cut[start]) + func(start , i , dp , cut)
                + func(i , end , dp , cut);
            
            if(min_cost > curr_cost || min_cost == INT_MAX)
            {
                min_cost=curr_cost;
            }
        }
        
        return dp[start][end]=min_cost;
    }
    int minCost(int n, vector<int>& cuts) {
        
        // we are given the weak points of a rod 
        
        // we will find out the cost for each weak points recusively 
        
        //  start=0 , end = m-1
        
        // we will be having a dp matrix for storing the min cost of each 
        
        // corresponding start & end 
        
        cuts.push_back(0);
        cuts.push_back(n);
		
		// 0 , n is pushed as there will be no cuts at that position , it will be helpful 
		
		// in taking finding the length i.e cuts[end]- cuts[start] , cuts will be from start+1 , end-1 , excluding the sides         
        sort(cuts.begin() , cuts.end());
        
        int m=cuts.size();
        
        vector<vector<int>> dp(m , vector<int>(m , -1) );
        
        int ans = func(0 , m-1 , dp , cuts );
        
        return ans;
    }
};