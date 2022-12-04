class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long int i=0,j=0,sum1=0,sum2=0;
        if(n==1)
        return 0;
        for(int i=1;i<n;i++)
        {
            sum2+=nums[i];
        }
        sum1=nums[0];
        int k=2,res=0,avg;
        avg=abs(sum1-sum2/(n-1));
        for(int i=1;i<n;i++)
        {
            sum1+=nums[i];
            sum2-=nums[i];
            int temp;
            if(n-k==0)
            temp=abs(sum1/k-0);
            else
            temp=abs(sum1/k-sum2/(n-k));
            if(temp<avg)
            {
                res=i;
                avg=temp;
            }
            k++;
        }
        return res;
    }
};