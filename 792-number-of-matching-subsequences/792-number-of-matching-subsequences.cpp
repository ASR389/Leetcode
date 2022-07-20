#include<bits/stdc++.h>
class Solution {
public:
	bool solve(string& s1,string &s2){
		int i = 0;
		int j = 0;
		
		while(i<s1.size() && j<s2.size()){
			if(s1[i]==s2[j]){
				i++;
				j++;
			}
			if(s1[i]!=s2[j]) i++;
			
		}
		if(j==s2.size()) return true;
		return false;
	}
	int numMatchingSubseq(string s, vector<string>& words) {
		int wordLen = words.size();
		unordered_map<string,bool> hash;
		int count = 0;
		for(int i=0;i<wordLen;i++){
			int m = s.size();
			if(hash.count(words[i]) == 0){
				if(solve(s,words[i])) {
					hash[words[i]] = true;
					count++;
				}
				else hash[words[i]] = false;
			}
			else{
				if(hash[words[i]]==true) count++;
			}
		}
		return count;
	}
};