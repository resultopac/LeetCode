class Solution {
public:

    void dfs(bool grandparent, bool parent, TreeNode* node,int& sum) {
        if (!node) {
            return;
        }
        if (grandparent) {
            sum += node->val;
        }
        if (parent) {
            if (node->val%2 == 0) {
                dfs(true,true,node->left,sum);
                dfs(true,true,node->right,sum);
            }else {
                dfs(true,false,node->left,sum);
                dfs(true,false,node->right,sum);
            }
        }else {
            if (node->val%2 == 0) {
                dfs(false,true,node->left,sum);
                dfs(false,true,node->right,sum);
            }else {
                dfs(false,false,node->left,sum);
                dfs(false,false,node->right,sum);
            }
        
        }
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        if (root->val%2 == 0) {
            dfs(false,true,root->left,sum);
            dfs(false,true,root->right,sum);
        }else {
            dfs(false,false,root->left,sum);
            dfs(false,false,root->right,sum);
        }
        return sum;
    }
    
};