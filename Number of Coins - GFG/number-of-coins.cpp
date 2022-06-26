// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int coins[], int m, int v ,int dp[]){
	    //base case
	    if(v==0) return 0;
	    
	    if(dp[v]!=-1)return dp[v];
	    
	    int ans = INT_MAX -1;
	    for(int i=0; i<m; i++){
	        if(v-coins[i]>=0){  //rem >=0 must
	            ans = min(ans,1+solve(coins,m,v-coins[i],dp));
	        }
	    }
	    dp[v] = ans;
	    return ans;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[10001];
	    
	    memset(dp,-1,sizeof(dp));
	    
	    int ans = solve(coins , M, V ,dp);
	    
        return ans == INT_MAX-1 ? -1 : ans; 
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends