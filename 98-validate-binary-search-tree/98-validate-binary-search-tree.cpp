class Solution {
public:
   void inOrder(TreeNode* root, vector<int>& v){
        if(root == NULL) return;
        
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        inOrder(root,v);
        
        for(int i =0; i<v.size()-1; i++){
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
};