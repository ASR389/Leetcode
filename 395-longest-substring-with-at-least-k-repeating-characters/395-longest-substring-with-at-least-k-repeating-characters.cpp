class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> hash;
        for (auto& c : s) {   // find the frequencies of all letter in string s 
            ++hash[c];
        }
        int ans = 0;
        int start = 0;
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            if (hash[s[i]] < k) {  // the letter whose freq smaller than k must be excluded
                int tmp = longestSubstring(s.substr(start, i - start), k);  // solve sub problems
                ans = tmp > ans ? tmp : ans;
                start = i + 1;
            }
        }
        if (start == 0) return N;
        int tmp1 = longestSubstring(s.substr(start, N - start), k);
        return max(tmp1, ans);
    }
};