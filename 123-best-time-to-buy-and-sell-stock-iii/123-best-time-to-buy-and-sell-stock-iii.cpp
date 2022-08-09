/*Buy and Sell Stock - III
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Anwer:



Brute Force O(N^2) is by divide and conquer is 

For each point we create a line and we use buy stock I‘s concept, what was it … to find the max profit in each of those two parts.
Time complexity is O(N^2)
*/

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         int ans=0;
//         for(int i=0;i<n;i++){
//             //for left side computation
//             int minsofar=INT_MAX;
//             int profit=0;
//             for(int k=0;k<=i;k++){
//                 if(minsofar>prices[k]){
//                     minsofar=prices[k];
//                 }
//                 profit=max(profit,prices[k]-minsofar);
//             }
//             //for right side computation
//             int minsofar2=INT_MAX;
//             int profit2=0;
//             for(int j=i+1;j<n;j++){
//                 if(minsofar2>prices[j]){
//                     minsofar2=prices[j];
//                 }
//                 profit2=max(profit2,prices[j]-minsofar2);
//             }
//             ans=max(ans,profit+profit2);
//         }
//         return ans;
//     }
// };

// Optimal

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        // int ans=INT_MIN;
        int n=nums.size();
        vector<int>left(n),right(n);
        //fill first transaction left B----->S | partition
        int leftmin=nums[0];
        for(int i=1;i<n;i++)
        {
            leftmin=min(leftmin,nums[i]);
            left[i]=max(left[i-1],nums[i]-leftmin);
        }
        //fill second transaction right to left towards partiton B<------S | partition
        int rightmax=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmax=max(rightmax,nums[i]);
            right[i]=max(right[i+1],rightmax-nums[i]);
        }
        //find the max-profit value
        int ans=right[0];
        for(int i=1;i<n;i++){
            ans=max(ans,left[i-1]+right[i]);
        }
        return ans;
    }
};