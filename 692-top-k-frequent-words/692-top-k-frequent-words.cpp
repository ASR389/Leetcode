class Solution {
public:
      static bool cmp(pair<int,string>&a,pair<int,string>&b)
        {
            if(a.first==b.first)return a.second<b.second;
            return a.first>b.first;
        }
        vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto c:words)mp[c]++;
        vector<pair<int,string>>ans;
        for(auto c:mp)ans.push_back({c.second,c.first});
        sort(ans.begin(),ans.end(),cmp);
        while(ans.size()>k)ans.pop_back();
        vector<string>ans2;
        for(auto c:ans)ans2.push_back(c.second);
        return ans2;
    }
};