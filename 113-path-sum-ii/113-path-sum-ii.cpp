/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	void pathSumHelper(TreeNode* root, int target, vector<vector<int>>& ans, vector<int>& store){
		if(!root){
			return;
		}
		store.push_back(root -> val);
		if(target == root -> val && !root -> left && !root -> right){
			ans.push_back(store);
		}
		pathSumHelper(root -> left, target - (root -> val), ans, store);
		pathSumHelper(root -> right, target - (root -> val), ans, store);
		store.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> ans;
		vector<int> store;
		pathSumHelper(root, targetSum, ans, store);
		return ans;
	}
};