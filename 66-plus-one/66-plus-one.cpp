class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int temp = digits[size - 1] + 1;
        digits[size - 1] = temp % 10;
        int rem = temp / 10;
        for(int i = size - 2 ; i >= 0 && rem != 0 ; i--){
            temp = digits[i] + rem;
            rem = temp / 10;
            digits[i] = temp % 10;
        }
        
        if(rem != 0)
            digits.insert(digits.begin(), rem);
        return digits;
    }
};