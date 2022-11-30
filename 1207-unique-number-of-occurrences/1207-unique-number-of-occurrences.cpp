class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>mp;
        for(auto i : arr){
            mp[i]++;
        }
        set<int>st;
        for(auto x : mp){
            st.insert(x.second);
        }
        if(mp.size() == st.size()) return true;
        return false;
    }
};
