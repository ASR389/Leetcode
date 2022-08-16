class Solution {
public:
int minSteps(string s, string t) {
        int N = s.size(), ans = 0;
        vector<int> map(26, 0); // frequency map for storing character frequencies
        
        // finding the equivalent frequencies after adding and removing elements in frequency map "map" 
        for (int i = 0; i < N; i++) {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        
        // adding the absolute values present map to our final answer
        for (int i = 0; i < 26; i++) ans += abs(map[i]);
        
        // only half of the unequal elements are to be replaced inorder to make the strings anagram
        return ans / 2;
    }
};