#include<bits/stdc++.h>
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string t = s;
        reverse(t.begin(), t.end());
        //now normal find LCS and that would be the LPS
        // LPS(s) = LCS(s,reverse(s)) => LCS(s,t)
        
        int m = s.size();
        int n = t.size();
        int dp[1001][1001];
        
        for(auto i : s) dp[i][0] = 0;
        for(auto i : t) dp[0][i] = 0;
        
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1]==t[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};