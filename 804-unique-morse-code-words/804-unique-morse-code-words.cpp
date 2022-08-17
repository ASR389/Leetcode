class Solution {
public:
    string solve(string s){
        vector<string>wrds={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string ans="";
        for(int i=0;i<s.size();i++) ans+=wrds[s[i]-'a'];
        return ans;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string,int>mp;
        for(int i=0;i<words.size();i++) mp[solve(words[i])]++;
        return mp.size();
    }
};
