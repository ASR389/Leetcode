class Solution {
public:
    unordered_map<string , bool>mp;
    bool solve(string s1, string s2){
        //base case
        if(s1.compare(s2) == 0) return true; // checks if length of both the string is equal or not
        
        if(s1.length()<=1) return false; // agar string 1 ya 1 se choti ho jati hai toh return false
        
        int n = s1.size();
        bool flag = false;
        
        string key = s1;
        key.push_back(' ');
        key.append(s2);
        
        if(mp.find(key) != mp.end()) return mp[key];
        
        for (int i = 1; i <= n - 1; i++) {     
            bool con1 = (solve(s1.substr(0, i), s2.substr(n - i, i))  &&
                         solve(s1.substr(i, n - i), s2.substr(0, n - i)) );
            
            bool con2 = (solve(s1.substr(0, i), s2.substr(0, i)) &&
                         solve(s1.substr(i, n - i), s2.substr(i, n - i)));
            
            if (con1 || con2) {
                flag = true;
                break;
            }
        }
        
        return mp[key] = flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        
        if(s1.size() != s2.size()) return false;

        return solve(s1,s2);
        
    }
};