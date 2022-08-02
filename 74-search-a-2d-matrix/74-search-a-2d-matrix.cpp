class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        

        if(n == 0 || m == 0)
            return false;

        int start = 0;
        int end = m*n - 1;
        
        while(start <= end)
        {
            int mid = (start + end)/ 2;

            int fm = matrix[mid/m][mid%m];
            
            if (target == fm)
                return true;

            else if(target < fm)
                end = mid - 1;
            else
                start = mid + 1;       
        }
        return false;
    }
};