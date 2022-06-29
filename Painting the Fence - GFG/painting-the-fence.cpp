// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long solve(int n, int k, long long dp[]){
        //for mod
        long long mod = 1000000007;
       //base case
       if(n==1) return k;
       if(n==2) return k*k;
       
       if(dp[n]!=-1) return dp[n];
       
       dp[n] = ((k-1) * ((solve(n-1, k, dp)%mod+solve(n-2, k, dp)%mod)))%mod;
       return dp[n];
    }
    long long countWays(int n, int k){
        long long dp[n+1];
        memset(dp,-1,sizeof(dp));
        
        return solve(n,k,dp);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends