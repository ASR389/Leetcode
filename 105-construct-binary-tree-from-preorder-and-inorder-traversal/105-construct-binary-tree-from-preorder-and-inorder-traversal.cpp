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
    
    void createmapping(vector<int> inorder, map<int,int>&nodemap, int n){
        
        for(int i=0; i<n; i++){
            nodemap[inorder[i]]=i;  
        }
      
    }
    
    TreeNode* solve(vector<int> preorder, vector<int> inorder, int& preOrderIndex,
                  int inorderStart, int inorderEnd, int n,map<int,int>&nodemap){
        //base case 
        if(preOrderIndex >= n || inorderStart>inorderEnd)
            return NULL;
        
        int element = preorder[preOrderIndex++];
        TreeNode* root = new TreeNode(element);
        int position = nodemap[element];
        
        root -> left = solve(preorder, inorder, preOrderIndex,inorderStart,position-1,n,nodemap);
        root -> right = solve(preorder, inorder, preOrderIndex,position+1,inorderEnd,n,nodemap);
        
        return root;
         
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        int preOrderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = n-1;
        
        map<int, int>nodemap;
        createmapping(inorder, nodemap,n);
        
        TreeNode* ans = solve(preorder, inorder, preOrderIndex,inorderStart,inorderEnd,n,nodemap);
        
        return ans;
    }
};