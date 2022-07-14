// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int dp[1001][1001];
		    int n = str.size();
		    string str1 = str;
		    string str2 = str;
		    for(auto i : str) dp[i][0]=0;
		    for(auto i : str) dp[0][i]=0;
		    
		    for(int i=1;i<n+1;i++){
		        for(int j=1; j<n+1; j++){
		                if(str1[i-1]==str2[j-1] && i!=j){
		                    dp[i][j] = 1 + dp[i-1][j-1];
		                }
		                else{
		                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		                }
		            
		        }
		    }
		    return dp[n][n];
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends