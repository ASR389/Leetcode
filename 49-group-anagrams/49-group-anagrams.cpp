class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
       vector<vector<string>>ans; // edge cases
      if(s.size()==1)  return {{s[0]}};
      unordered_map<string,vector<string>>m; // key value is sorted string and vector store the anagrams
      for(auto i:s) {
        string str=i;
        sort(i.begin(),i.end());
        m[i].push_back(str);
      }
      for(auto i:m)
        ans.push_back(i.second); 
    return ans;
    
    }
};