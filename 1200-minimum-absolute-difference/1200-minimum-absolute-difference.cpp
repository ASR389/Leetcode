class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int mi=INT_MAX;
        int i;
        int n=arr.size();
        for(i=1;i<n; i++)
        {
            mi=min(mi,arr[i]-arr[i-1]);
        }
        vector<vector<int> > v;
        for(i=1; i<n; i++)
        {
            if(arr[i]-arr[i-1]==mi)
            {
                vector<int> vv;
                vv.push_back(arr[i-1]);
                vv.push_back(arr[i]);
                v.push_back(vv);
            }
        }
        return v;
          
    }
};