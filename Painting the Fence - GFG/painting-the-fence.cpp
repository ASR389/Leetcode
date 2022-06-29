// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long solve(int n, int k){
        //for mod
        long long mod = 1000000007;
       //base case
    long long dp[n+1];
    dp[1] = k;
    dp[2] = k*k;
       
    //   solve using tabulation
       for(int i=3; i<=n; i++){
       dp[i] = ((k-1) * ((dp[i-1]%mod+dp[i-2]%mod)))%mod;
       }
       return dp[n];
    }
    long long countWays(int n, int k){
        return solve(n,k);
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