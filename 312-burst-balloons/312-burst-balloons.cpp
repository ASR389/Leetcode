class Solution {
public:

	int dp[305][305];

	int maxcoins(vector<int> &nums,int i,int j){
		if(i > j)return 0;

		if(dp[i][j]!=-1)
			return dp[i][j];

		int mx = INT_MIN;

		for(int k=i;k<=j;k++){
			int z = nums[k] * nums[i-1] * nums[j+1] + maxcoins(nums,i,k-1) + maxcoins(nums,k+1,j);
			mx = max(mx,z);
		}
		return dp[i][j] = mx;
	}

	int maxCoins(vector<int>& nums) {
		memset(dp,-1,sizeof(dp));
		int n = nums.size();
		nums.push_back(1);
		nums.insert(nums.begin(),1);
		return maxcoins(nums,1,n);
	}
};