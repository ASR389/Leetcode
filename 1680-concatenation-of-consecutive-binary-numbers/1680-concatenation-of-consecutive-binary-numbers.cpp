class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int mod = 1e9+7, l;
        
        /*
        log2(8) means 2 is the base and 8 is value, log2(8) = 3 ,it needs 4 bits to represents the value.
        therefore l = log2(i)+1;
        
        for i=1 to n find no: of bits required to represent i in binary i.e l now left shift the ans l times
        which is equivalent to multiply ans with pow(2,l) and then add i. We left shifting l times because see
        we have to concatenate i which is l bits in length so we need extra l bits
        For eg : 
        ans=0,n=3;
        for i = 1(1), ans=0, l=1 so ans<<l = 0 now add 1 so ans becomes 1
        for i = 2(10), ans=1, l=2 so ans<<l = 1*(pow(2,2)) = 4, now add i to ans so ans becomes 6
        for i = 3(11), ans=6, l=2 so ans<<l = 6*(pow(2,2)) = 24, now add i to ans so ans becomes 27
        */
        
        for(int i=1 ; i<=n ; i++){
            l = log2(i)+1;
            ans = ((ans<<l)+i)%mod;
        }
        return ans;
    }
};