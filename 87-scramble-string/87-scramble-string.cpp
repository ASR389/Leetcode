class Solution {
public:
    unordered_map<string , bool>mp;
    bool solve(string s1, string s2){
        int n = s1.size();
        //base case
        if(s1 == s2) return true; // checks if length of both the string is equal or not
        
        // if(n<=1) return false; // agar string 1 ya 1 se choti ho jati hai toh return false
          
        // making key    "s1"space"s2"  "s1 s2"
        
        // string key = s1;
        // key.push_back(' ');
        // key.append(s2);
        
        string key = s1+' '+s2;   //simple way of making key
        
        // checking key in map before function call 
        
   //yeh jb tak chalta hai jb tak value last tk mil na jaye agar mil gayi toh return value else go to solve fxn     
        if(mp.find(key) != mp.end())   
            return mp[key];
        
        //function call
        bool flag = false; 
        for (int i = 1; i <= n - 1; i++) {     
            bool con1 = (solve(s1.substr(0, i), s2.substr(n - i, i))  &&      //for (gr)(eat) -> (eat)(gr)
                         solve(s1.substr(i, n - i), s2.substr(0, n - i)) );
            
            bool con2 = (solve(s1.substr(0, i), s2.substr(0, i)) &&           //for(gr)(eat) ->  (gr)(eat) 
                         solve(s1.substr(i, n - i), s2.substr(i, n - i)));
            
            if (con1 || con2) {
                flag = true;
                break;
            }
        }
        //storing key in map and also returning value stored in map
        return mp[key] = flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        
        if(s1.size() != s2.size()) return false;

        return solve(s1,s2);       
    }
};