class Solution {
public:
    int largestOverlap(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n= nums1.size();
        int ans=0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                int temp1=0;
                int temp2=0;
                for (int p=i; p<n; p++)
                {
                    for (int q=j; q<n; q++)
                    {
                        if (nums2[p][q]==1 && nums1[p-i][q-j]==1)temp1++;
                        if (nums1[p][q]==1 && nums2[p-i][q-j]==1)temp2++;
                    }
                }
                ans= max(temp1, ans);
                ans= max(temp2, ans);
            }
        }
        for (int i=0; i<n; i++)
        {
            for (int j=n-1; j>=0; j--)
            {
                int temp1=0;
                int temp2=0;
                
                for (int p=i; p<n; p++)
                {
                    for (int q=j; q>=0; q--)
                    {
                        if (nums2[p][q]==1 && nums1[p-i][q+n-1-j]==1)temp1++;
                        if (nums1[p][q]==1 && nums2[p-i][q+n-1-j]==1)temp2++;
                    }
                }
                ans= max(temp1, ans);
                ans= max(temp2, ans);
            }
        }
        return ans;
    }
};