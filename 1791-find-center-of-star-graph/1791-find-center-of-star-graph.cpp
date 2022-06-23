class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        map<int,int>mp;
        
        int m=0;
        
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
            
            m = max(m,max(edges[i][0],edges[i][1]));
        }
        
        for(auto it:mp)
        {
            if(it.second==m-1)return it.first;
        }
        
        return -1;
        
    }
};