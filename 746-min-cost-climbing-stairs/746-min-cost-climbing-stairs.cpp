class Solution {
public:
    int dp[1000];
    int find(int n, vector<int>& cost){
        if(n>=cost.size())
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int t1 = find(n+1, cost);
        int t2 = find(n+2, cost);
        return dp[n]= cost[n]+min(t1, t2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        for( int i=0; i<1000; i++) dp[i]=-1;
        return min(find(0,cost), find(1,cost));
    }
};