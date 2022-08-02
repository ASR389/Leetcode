class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int>v;
        int row=matrix.size();
        int col=matrix[0].size();
        
          int count=0;
        int total=row*col;
        
        int startRow=0;
        int startCol=0;
        int endRow=row-1;
        int endCol=col-1;
        
      
       
        
        while(count<total){
            
            //print starting row
            for(int i=startCol;count<total && i<=endCol;i++)
            {
                v.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            
            //print ending column
            
             for(int i=startRow;count<total && i<=endRow;i++)
            {
                v.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            
            //print ending row
            
             for(int i=endCol;count<total && i>=startCol;i--)
            {
                v.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            
            //print starting column
            
             for(int i=endRow;count<total && i>=startRow;i--)
            {
                v.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
            
        }
          return v;
    }
  
};