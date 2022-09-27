class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = "";
        vector<int>  ltr(dominoes.size(),0);
        vector<int> rtl = ltr;
        int count=1;
        char prev = '.';
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i]=='R'){
                prev= 'R';
                count=1;
                continue;
            } else if(dominoes[i]=='L') prev= 'L';
            if(prev=='R' && dominoes[i]=='.') ltr[i]=count++;
        }
        count=1;
        prev='.';
        for(int i=dominoes.size()-1;i>=0;i--){
            if(dominoes[i]=='L'){
                prev= 'L';
                count=1;
                continue;
            } else if(dominoes[i]=='R') prev= 'R';
            if(prev=='L' && dominoes[i]=='.') rtl[i]=count++;
        }
        for(int i=0;i<dominoes.size();i++){
            if(ltr[i]==0 & rtl[i]==0) ans+=dominoes[i];
            else if(rtl[i]==0) ans+='R';
            else if(ltr[i]==0) ans+='L';
            else if(ltr[i] == rtl[i]) ans+='.';
            else if(ltr[i] < rtl[i]) ans+='R';
            else ans+='L';
        }
        
        return ans;
    }
};