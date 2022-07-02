class Solution {
public:
     int t[501];
    int solve(vector<int>& arr, int k,int index,int n){
        if(index>=n)
            return 0;
        
        int len=0;
        int maxElement=INT_MIN;
        int ans=INT_MIN;
        
        if(t[index]!=-1)
            return t[index];
        for(int j=index ; j<min(n,index+k)  ;j++){
            len++;
            maxElement=max(maxElement,arr[j]);
            
            int sum=len*maxElement+solve(arr,k,j+1,n);
            
            ans=max(ans,sum);
            
        }
        
        return t[index]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(t,-1,sizeof(t));
        return solve(arr,k,0,n);
    }
};