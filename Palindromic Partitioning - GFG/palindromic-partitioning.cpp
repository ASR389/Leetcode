// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501]; 
    bool isPalindrome(string &str,int i,int j){
        while(str[i]==str[j]){
            i++;
            j--;
        if(i>j) return true;
     }
     return false;
    }
     
    int solve(string &str, int i , int j){
        // base case
        if(i>=j) return 0;
        if(isPalindrome(str,i,j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        // MCM conditions
        int ans = INT_MAX;
        for(int k = i; k<=j-1; k++){
            int temp =  solve(str,i,k) + 1 + solve(str, k+1, j);
            ans = min(ans,temp);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        int n = str.length();
        return solve(str,0,n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends