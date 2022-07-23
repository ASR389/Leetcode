class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> v;
        int size = arr.size();

        sort(arr.begin(), arr.end());
        
        int i=0;
        while(i<size) {
            int count = 1;
            for(int j=i+1; j<size; j++){
                if(arr[i] == arr[j]) {
                    count++;
                } else {
                    break;
                }
            }
            v.push_back(count);
            i += count;
        }
        
        size = v.size();
        sort(v.begin(), v.end());
        
        for(i=0; i<size-1; i++) {
            if(v[i] == v[i+1]) {
                return false;
            }
        }
        return true;
        
    }
};
