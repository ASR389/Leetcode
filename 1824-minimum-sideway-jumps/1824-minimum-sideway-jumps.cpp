class Solution {
public:
    int dp[4][1000005];
    int solve(vector<int>& obstacles,int currpos, int currlane){
        //base case
        if(currpos == obstacles.size()-1) return 0;
        
        if(dp[currlane][currpos] != -1) return dp[currlane][currpos];
        
        if(obstacles[currpos+1] != currlane){
            return solve(obstacles,currpos+1,currlane);
        }
        else{
            //sideways jump
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
            if(currlane != i && obstacles[currpos] != i){
               ans = min(ans, 1 + solve(obstacles,currpos,i)); 
            }
          } 
            return dp[currlane][currpos] = ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        memset(dp,-1,sizeof(dp));
        return solve(obstacles,0,2);
        
    }
};