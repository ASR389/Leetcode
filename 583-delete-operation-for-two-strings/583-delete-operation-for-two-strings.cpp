class Solution {
public:
    int minDistance(string str1, string str2) {
        int dp[1001][1001];
	    int m = str1.size();
	    int n = str2.size();
	    //Initialization
	    for(int i=0; i<m+1; i++) dp[i][0] = 0;
	    for(int i=0; i<n+1; i++) dp[0][i] = 0;
	    //finding LCS length
	    for(int i=1; i<m+1; i++){
	        for(int j=1; j<n+1; j++){
	            if(str1[i-1]==str2[j-1])
	            dp[i][j] = 1+dp[i-1][j-1];
	            else
	            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    
	    int lcs = dp[m][n];   
	    int del = m-lcs;
	    int ins = n-lcs;
	    
	    return del+ins;
    }
};