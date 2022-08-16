


class Solution {
public:
    int answer;
    void helper(TreeNode* temp,int &k){
        if(!temp)return;

        helper(temp->left,k);
        k--;

        if(k==0){
            // cout<<temp->val<<" ";
            answer=temp->val;
            return;
        }
        helper(temp->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return answer;

    }
};