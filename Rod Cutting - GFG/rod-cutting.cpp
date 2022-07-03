// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
int cutRod(int price[], int n) {
       //code here
       int size=sizeof(price);
      size=size+1;
       int dp[size+1][n+1];
       for(int i=0;i<=size;i++) dp[i][0]=0;
       for(int j=0;j<=n;j++) dp[0][j]=0;
       
       for(int i=1;i<=size;i++)
       for(int j=1;j<=n;j++){
           if(i<=j) dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
           else dp[i][j]=dp[i-1][j];
       }
       return dp[size][n];
   }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends