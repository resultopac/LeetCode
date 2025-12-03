using namespace std;

int recursive(TreeNode* root,int& val) {
    if (root == nullptr) {
        return 0;
    }
    recursive(root->right,val);
    val += root->val;
    root->val = val;
    recursive(root->left,val);
    return 0;
}

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;
        recursive(root,val);
        return root;
    }
};