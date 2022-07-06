class Solution {
public:
    
    int no_of_one(int n,int m,int i,int j,vector<vector<int>>& board){
        int count=0;
        if( j<m-1 and board[i][j+1]==1)count++;
        if(j>0 and board[i][j-1]==1 )count++;
        if( i<n-1 and board[i+1][j]==1 )count++;
        if(i>0 and board[i-1][j]==1 )count++;
        if(i<n-1 and j<m-1 and board[i+1][j+1]==1 )count++;
        if( i<n-1 and j>0 and board[i+1][j-1]==1 )count++;
        if( i>0 and j<m-1 and board[i-1][j+1]==1 )count++;
        if( i>0 and j>0 and board[i-1][j-1]==1 )count++;
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> ans=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0){
                    if(no_of_one(n,m,i,j,board)==3)ans[i][j]=1;
                }
                else{
                    if(no_of_one(n,m,i,j,board)<2)ans[i][j]=0;
                    else if(no_of_one(n,m,i,j,board)>3)ans[i][j]=0;
                    else continue;
                }
            }
        }
        board=ans;
    }
};