class Solution {
public:
    bool check(vector<int>& weights, int days, int capacity){
        int cur = 0, cntd = 0;
        for(int i=0; i<weights.size(); i++){
            if(cur+weights[i] > capacity){
                cntd++;
                cur = weights[i];
            }else{
                cur += weights[i];
            }
            if(cntd > days) return false;
        }
        cntd++;
        return cntd <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = INT_MIN, r = 0;
        for(int i=0; i<weights.size(); i++){
            r += weights[i];
            l = max(l,weights[i]);
        }
        int res;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(weights,days,mid)){
                res = mid;
                r = mid-1;       
            }else{
                l = mid+1;
            }
        }
        return res;
    }
};