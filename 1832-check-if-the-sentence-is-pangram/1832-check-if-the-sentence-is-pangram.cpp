class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> arr(26, false);
        for (auto i:sentence)
            arr[i-'a']=true;
        for (auto i:arr)
            if (!i) return i;
        return true;
    }
};