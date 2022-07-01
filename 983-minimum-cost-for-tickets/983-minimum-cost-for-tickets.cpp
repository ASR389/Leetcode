class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int index, vector<int>&dp){
        //base case
        if(index >= days.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        //1-day pass
        int option1 = costs[0] + solve(days, costs, index+1, dp);
        
        int i;  
        //7-day pass
        for(i=index; i<days.size() && days[i] < days[index]+7; i++);
        int option2 = costs[1]  + solve(days,costs,i,dp); //i is index after 7 days
        //yaha pe i hai 7din ke baad agla konsa index 
        
        //30-day pass
        for(i=index; i<days.size() && days[i] < days[index]+30; i++);
        int option3 = costs[2]  + solve(days,costs,i,dp);
        
        dp[index] = min(option1,min(option2,option3));
        
        return dp[index];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return solve(days,costs,0,dp);
    }
};