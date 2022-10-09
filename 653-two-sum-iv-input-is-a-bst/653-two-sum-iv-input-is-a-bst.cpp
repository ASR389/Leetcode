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
    vector<int> arr;
    // Inorder - Initialize array (Increasing order)
    void initArr(TreeNode* node){
        if(!node) return;
        initArr(node->left);
        arr.emplace_back(node->val);
        initArr(node->right);
    }
    
    bool find(int &k){
        int l=0,r=arr.size()-1;
        while(l<r){
            int sum=arr[l]+arr[r];
            if(sum==k){
                return true;
            }
            sum<k ? l++ : r--;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        initArr(root);
        return find(k);
        
    }
};