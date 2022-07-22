class Solution {
public:    
    vector<vector<int>> threeSum(vector<int>& nums) {
		// make answer array
        vector<vector<int>> ans; 
		
		// corner case
        if(nums.size() < 3) return ans;
		
		// sort the array
        sort(nums.begin(), nums.end()); 
        
		// iterate over the array to fix first digit
        for (int i = 0; i < nums.size()-2; i++) 
        {    
			//we want no duplicates so we add this if
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) 
            {       
                int l = i+1, h = nums.size()-1, sum = 0 - nums[i];
                
				// now find other two elemnts in left over array
                while (l < h) {
                    if (nums[l] + nums[h] == sum) 
                    {
                        vector<int> temp = {nums[i], nums[l], nums[h]}; 
                        ans.push_back(temp);
                        
						// to avoid duplicates
                        while (l < h && nums[l] == nums[l+1]) l++;
                        while (l < h && nums[h] == nums[h-1]) h--;
                        l++; h--;
                    } 
                    else if (nums[l] + nums[h] < sum) l++;
                    else h--;
               }
            }
        }
		
		// return answer
        return ans;
    }
};