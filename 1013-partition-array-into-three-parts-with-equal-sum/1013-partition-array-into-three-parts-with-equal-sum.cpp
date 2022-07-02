class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int n = arr.size();
        
        // find total sum
        
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        
        // not possible to partition into three parts
        
        if(sum % 3)
            return false;
        
        // sum of each partition
        
        int target = sum / 3;
        
        int i = 0;
        
        int count = 0;
        
        while(i < n)
        {
            int curr_sum = 0;
            
            while(i < n && curr_sum + arr[i] != target)
            {
                curr_sum += arr[i];
                
                i++;
            }
            
            // if partition is found increment count
            
            if(i < n)
            {
                count++;
            }
            
            i++;
        }
        
        return count >= 3;
    }
};