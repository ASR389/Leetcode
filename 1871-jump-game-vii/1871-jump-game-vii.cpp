class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> reach(s.size(), 0);
        reach[0]=1;
        
        for( int i=0, last=0; i<s.size()&&last<s.size()-1; i++){
            if(s[i]=='0'&&reach[i]==1){
                for( int j=max( i+minJump, last); j<=min( i+maxJump, s.size()-1); j++){
                    if(s[j]=='0')   reach[j]=1;
                }
                last=min( i+maxJump, s.size()-1);
            }
        }
        
        return reach.back()==1;
    }
    
protected:
    int min( int a, int b){
        return a<b?a:b;
    }
    
    int max( int a, int b){
        return a<b?b:a;
    }
};