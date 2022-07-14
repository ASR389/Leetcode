class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        
        int m = a.size();
        int n = b.size();
        int dp[1001][1001];
        
        for(auto i : a) dp[i][0] = 0;
        for(auto i : b) dp[0][i] = 0;
        
        for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int i = m;
        int j = n;
        string s = "";
        
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                s.push_back(a[i-1]);
                i--;
                j--;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                s.push_back(b[j-1]);
                j--;
            }
            else{                       //if(dp[i-1][j]>dp[i][j-1]) don't write as no else after if so TLE
                s.push_back(a[i-1]);
                i--;
            }
        }
        
        while(i>0){
            s.push_back(a[i-1]);
            i--;
        }
        while(j>0){
            s.push_back(b[j-1]);
            j--;
        }
        
        reverse(s.begin(),s.end());
        return s;
    }
};