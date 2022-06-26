class Solution {
public:
    int solve(int n){
        //base case
        int prev1 = 1;
        int prev2 = 0;
  //tabulation method  with space optimization        
        for(int i = 2; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int fib(int n) {        
        if(n == 0) return 0; //yeh dhyan rakh lena ki 0 ho toh reutrn 0 kr de
        int ans = solve(n);
        
        return ans;
        
    }
};