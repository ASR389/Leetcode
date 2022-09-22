class Solution {
public:
string reverseWords(string s) {
        string res="";
        int i=0,n=s.length();
        while(i<n){
            while(i<n && s[i]==' ')
                i++;
            if(i>=n)
                break;
            int j=i+1;
            while(j<n && s[j]!=' ')
                j++;
            string f=s.substr(i,j-i);
            if(res.length()==0)
                res=f;
            else
                res=f+" "+res;
            i=j;
        }
        return res;
    }
};