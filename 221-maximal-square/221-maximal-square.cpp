class Solution {
public:
    int dp[305][305];
    int solve(vector<vector<char>> &mat,int i, int j, int& maxi){
    
    //base case
    if(i>=mat.size() || j>=mat[0].size()) //mat se bahar nikal gaye
        return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
    int right = solve(mat , i , j+1, maxi);
    int diagonal = solve(mat, i+1, j+1, maxi);
    int down = solve(mat, i+1, j, maxi);
        
    if(mat[i][j] == '1'){  // agar jaha khade hai wo 1 hai toh aange dekho
        int ans = 1 + min(right,min(diagonal,down)); //1+ bcoz jaha khade hai uss 1 size ko add
        maxi = max(maxi, ans*ans);  //chage here ans*ans bcoz here asked ares so multiply 
        return dp[i][j] = ans;
    }   
    else{  //warna agar 0 hai toh square ban hi sakta so return 0
        return dp[i][j] = 0;
    }
}
    int maximalSquare(vector<vector<char>>& matrix) {
      memset(dp,-1,sizeof(dp));
        
        int maxi = 0;
        solve(matrix,0,0,maxi);
        return maxi;
    }
};