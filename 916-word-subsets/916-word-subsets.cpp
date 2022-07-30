class Solution {
public:
    vector<string> wordSubsets(vector<string>& u, vector<string>& s) {
        vector<string > v;
        int arr[26];
        for(int i=0;i<26;i++)
                arr[i]=0;
        
        for(int i=0;i<s.size();i++)
        {
            int t[26] ;
            for(int i=0;i<26;i++)
                t[i]=0;
            for(int j=0;j<s[i].length();j++)
               t[s[i][j]-'a']++;
            
            for(int i=0;i<26;i++)
                arr[i]=max(arr[i],t[i]);
        }
        
        for(int i=0;i<u.size();i++)
        {
            bool push=true;
            int t[26] ;
            for(int i=0;i<26;i++)
                t[i]=0;
            
            for(int j=0;j<u[i].length();j++)
               t[u[i][j]-'a']++;
            
            for(int j=0;j<26;j++)
            {
                if(t[j]<arr[j])
                    push=false;
            }
            
            if(push)
                v.push_back(u[i]);
            
        }
        
            return v;
    }
};