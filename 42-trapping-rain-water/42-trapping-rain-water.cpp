class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int> right(n,0);
        vector<int> left(n,0);
        
        int temp = INT_MIN;
        for(int i=n-1; i>=0; i--){
                temp = max(height[i],temp);
                right[i] = temp;
        }
        temp = INT_MIN;
        for(int i=0; i<n; i++){
                temp = max(height[i],temp);
                left[i] = temp;
        }
        
        for(int i=0; i<n; i++){
          ans += abs(min(left[i],right[i]) - height[i]);
        }
        return ans;
    }
};