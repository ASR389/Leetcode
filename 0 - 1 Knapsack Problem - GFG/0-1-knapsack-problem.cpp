// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int solve(int W, int wt[], int val[], int n, int dp[][10001]){
        // base case
        if(W == 0 || n == 0) return 0;
        
        if(dp[n-1][W]!=-1) return dp[n-1][W];

        if(wt[n-1] > W) return solve(W, wt, val, n-1, dp);
        
        // now two case 
        // 1 include
        // 2 exclude

        else{
            int include = val[n-1] + solve(W-wt[n-1], wt, val,n-1,dp);
            int exclude = 0 + solve(W, wt, val, n-1,dp);
            dp[n-1][W] = max(include,exclude);
            return dp[n-1][W];
        }
        // return ans;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // we take 2D-dp array because 2 variables are changing
        // 1->index(n) 2-> W capacity
        int dp[101][10001];
        memset(dp,-1,sizeof(dp));
       return solve(W,wt,val,n,dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends