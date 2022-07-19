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
    map<TreeNode*, int> dp; 
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        
      if(dp.count(root)) return dp[root];
        
        int first  = 0;
        int second = 0;
        int third = 0;
        int fourth = 0;
        
        if(root->left != NULL) {
             first = rob(root->left->left);
             second = rob(root->left->right);
        }   
        if(root->right != NULL) {
            third = rob(root->right->left);
            fourth = rob(root->right->right);
        }
        
        int firstWay = root->val + first + second + third + fourth;
        int secondWay = rob(root->left) + rob(root->right);

        return dp[root] = max(firstWay, secondWay);
    }
};