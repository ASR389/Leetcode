class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string res="";
        for(int i=0;i<size(s);i++)
        {
            if(s[i]==' '){
                v.push_back(res);
                res="";
            }
            else
            res+=s[i];
        }
        // for last word which maynot encounter space
        v.push_back(res);
        
        if(size(v)!=size(pattern))return false;
        
        
        unordered_map<char,string>mp;
        set<string>st;// for unique string 
        for(int i=0;i<size(pattern);i++)
        {
            if(mp.find(pattern[i])!=mp.end())
            {
               if(mp[pattern[i]] != v[i])return false ;
            }
            else{
                //"abba"
                //"dog dog dog dog"
                if(st.count(v[i])>0)return false;
                 mp[pattern[i]]=v[i];
                st.insert(v[i]);
            }
               
        }
        return true;
    }
};