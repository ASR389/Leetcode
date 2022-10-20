class Solution {
public:
    int romanToInt(string s) {

// we have to care about when to minus some element and when  to add some element 
 // vi -> 5+1 
 // iv -> -1+5
    unordered_map<char,int>m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int ans =0;
     for(int i=0;i<s.size();i++){
         ans+= m[s[i]]< m[s[i+1]] ?-m[s[i]] :m[s[i]];
    }
    return ans ;
    }
};