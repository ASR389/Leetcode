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
    int solve(TreeNode* root, int& res){
        //base case
        if(root == NULL) return 0;
        
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        
        int temp = 1 + max(l,r);     //storing temp ki answer mere root se hoke ja raha hai
        int ans = max(temp, 1+l+r);  //answer mere lst + rst +1 se aa raha hai leke temp se cmp kr lo
        
        res = max(res,ans);  //final answer res mai store kara do jo max aa raha ho
        
        return temp;  // l,r diameter calculate krne k liye
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res-1;
    }
};