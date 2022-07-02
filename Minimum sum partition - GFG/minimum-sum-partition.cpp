// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    bool subsetSum(int nums[], int n, int sum,vector<vector<int>> &dp){
        
        for(int i=0; i<sum+1; i++) dp[0][i] = 0;
        for(int i =0; i<n+1; i++) dp[i][0] = 1;
        
         for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1]<=j){ 
                    dp[i][j] = (dp[i-1][j-nums[i-1]] || dp[i-1][j]);
                    }
                else
                    dp[i][j] = dp[i-1][j];
            }
         }
        return dp[n][sum];
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));  
        
        subsetSum(arr,n,sum,dp);
        
        vector<int>v;   
        for(int i=0; i<=sum/2; i++){
            if(dp[n][i] == true){
                v.push_back(i);
            }
        }
        
        int ans = INT_MAX;
        for(int i =0; i<v.size(); i++){
            ans = min(ans,abs(sum-2*v[i]));
        }
          
        return ans;
    
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends