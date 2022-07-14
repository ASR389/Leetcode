class Solution {
public:
    bool isSubsequence(string s, string t) {
        //we can also do by LCS if LCS == s.length() return true
        if(s.size()==0){
            return true;
        }
        int j=0;
        
        for(int i=0;i<t.size();i++){
            if(s[j]==t[i]){
                j++;
            }
            
            if(j==s.size()){
                return true;
            }
        }
        return false;
    }
};