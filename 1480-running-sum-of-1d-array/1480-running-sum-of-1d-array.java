class Solution {
    public int[] runningSum(int[] nums) {
        
        int[] sum = new int[nums.length];
        sum[0]=nums[0];
        for(int i=0;i<nums.length-1;i++)
        {
            sum[i+1]=sum[i]+nums[i+1];
        }
        return sum;
    }
}