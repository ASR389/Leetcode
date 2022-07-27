class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int row = mat.size();
        int col = mat[0].size();
        
        if(row * col != r * c) return mat;
        
        vector<vector<int>> ans(r,vector<int>(c,0));

        int i = 0;
        int j = 0;
        
        for(int m = 0; m < row; m++){
            for(int n = 0; n < col; n++){
                    
                if(j < c){
                    ans[i][j++] = mat[m][n];
                }
                else{
                    j = 0;
                    ans[++i][j++] = mat[m][n];
                }
            }
        }
        
        return ans;
        
    }
};