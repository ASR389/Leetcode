class Solution {
public:
    string reverseWords(string s) {
        stack<char> stck;
        stck.push('1');
        string ans= "";
        for(int i=0; i<=s.length(); i++){
            stck.push(s[i]);
            if(s[i] == ' ' || i==s.length()){
                stck.pop();
                while(stck.top() != '1'){
                    char a = stck.top();
                    ans += a;
                    stck.pop();
                }
                if(i!=s.length())
                ans+=" ";
            }
        }
       return ans;
    }
};