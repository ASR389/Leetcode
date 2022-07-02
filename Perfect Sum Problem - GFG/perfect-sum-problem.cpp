// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
int perfectSum(int arr[], int n, int sum)
{
    int mod=1000000007;
      int dp[n+1][sum+1];
      //base case 
     /*here we are sure about the 1st row only
     as elements of array containing 0 also and we canot 
     initialise the sum 0 with only one subset */
     for(int j=0;j<sum+1;j++){
         dp[0][j]=0;
     }
     for(int i =0; i<n+1; i++){
     dp[i][0]=1;
     }
      
      //now our main algo
      
      /*now fill all the remaining boxes*/
      for(int i=1;i<n+1;i++){
      for(int j=0;j<sum+1;j++){
         if(arr[i-1]<=j){
           //include and exclude and  store total count
           dp[i][j]=(dp[i-1][j]%mod +dp[i-1][j-arr[i-1]]%mod)%mod;
         }
         else{
             dp[i][j]=dp[i-1][j]%mod;
         }
      }
      }
     // and lastly return as we do in dp 
      return dp[n][sum];
}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends