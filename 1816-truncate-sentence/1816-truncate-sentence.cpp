class Solution {
public:
    string truncateSentence(string s, int k) {
        int count =0 ;
        string str = "" ;
        int ans ;
        for (int i=0 ; i<s.size() ; i++){
            if(s[i] == ' '){
                count ++ ;
                if(count == k ){
                    ans = i ;
                }
            }  
        }

        for (int i=0 ; i<ans ; i++){
            str += s[i] ;
        }

        
        
        if(count >= k ){
            return str ;
        }
        else {
            return s ;
        }
       
    }
};