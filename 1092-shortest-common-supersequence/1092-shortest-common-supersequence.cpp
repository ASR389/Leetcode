class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        
        if(s==t) return s;
        
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
		// INITIALIZATION
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=m;i++) dp[0][m]=0;
        
		// Finding LCS
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]= 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string lcs,ans;
        
		//EVALUATING LCS FROM TABLE & STORING IT
        int i = n, j = m;
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                lcs.push_back(s[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1])
                    i--;
                else 
                    j--;
            }
        }
        
		// REVERSING LCS AS IT WAS CALCULATED FROM TOP DOWN DP
        reverse(lcs.begin(),lcs.end());
        
        i=0,j=0;
        int k=0;
		
		// MERGING LCS & ADDING OTHER Non-Duplicate CHARACTERS
        while(i<n && j<m){
            if(s[i]==t[j]){
                ans.push_back(s[i]);
                i++;
                j++;
                k++;
            } 
            else{
                if(s[i]==lcs[k]){
                    ans.push_back(t[j]);
                    j++;
                }
                else if(t[j]==lcs[k]){
                    ans.push_back(s[i]);
                    i++;
                }
                else{
                    ans.push_back(s[i]);
                    ans.push_back(t[j]);
                    i++;
                    j++;
                }
            }
        }
        
        while(i<n){
            ans.push_back(s[i]);
            i++;
        }
        
        while(j<m){
            ans.push_back(t[j]);
            j++;
        }
        
        return ans;
    }
};