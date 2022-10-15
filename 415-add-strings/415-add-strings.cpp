class Solution {
public:
string addStrings(string num1, string num2) {
        int m=num1.length()-1;
        int n=num2.length()-1;
        
        // cout<<num1[m-1]-'0';
        int carry = 0;
        // int i=m-
        string ans = "";
        while(m>=0 || n>=0 || carry){
            int sum=0;
            if(m>=0) sum += (num1[m]-'0');
            if(n>=0) sum += (num2[n]-'0');
            sum += carry; 
            carry = sum / 10;
            sum = sum % 10;
            ans += to_string(sum);
            m--;
            n--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};