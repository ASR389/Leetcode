class Solution {
public:
    int maxOf3(int a, int b, int c){
    if(a>b) {
        return c>a ? c:a;
    }
     return c>b ? c:b;
}

    string longestDiverseString(int a, int b, int c) {
       string str = "";
    int freq[3] = {0,0,0};
    
    while(a!=0&&b!=0|| b!=0&&c!=0|| a!=0&&c!=0) {
        int max = maxOf3(a,b,c);
        
        if(max == a) {
            if(freq[0]==2) {
                if(b>c) {
                    str += 'b';
                    b--;
                    freq[1]++; freq[2]=0;
                }
                else{
                    str += 'c';
                    c--;
                    freq[2]++; freq[1]=0;
                }
                freq[0] = 0;
            }
            else{
                str += 'a';
                freq[0]++; freq[1]=0; freq[2]=0;
                a--;
            }
        }
        else if(max == b) {
            if(freq[1]==2) {
                if(a>c) {
                    str += 'a';
                    a--;
                    freq[0]++; freq[2]=0;
                }
                else{
                    str += 'c';
                    c--;
                    freq[2]++; freq[0]=0;
                }
                freq[1] = 0;
            }
            else{
                str += 'b';
                freq[1]++; freq[0]=0; freq[2]=0;
                b--;
            }
        }
        else{
            if(freq[2]==2) {
                if(b>a) {
                    str += 'b';
                    b--;
                    freq[1]++; freq[0]=0;
                }
                else{
                    str += 'a';
                    a--;
                    freq[0]++; freq[1]=0;
                }
                freq[2] = 0;
            }
            else{
                str += 'c';
                freq[2]++; freq[0]=0; freq[1]=0;
                c--;
            }
        }
    }
    
    int i=0; 
    while(a!=0) {
        if(i>=2) break;
        str += 'a';
        a--;
        i++;
    }
    i=0;
    while(b!=0) {
        if(i>=2) break;
        str += 'b';
        b--;
        i++;
    }
    i=0;
    while(c!=0) {
        if(i>=2) break;
        str += 'c';
        c--;
        i++;
    }
    
    return str;
 
    }
};