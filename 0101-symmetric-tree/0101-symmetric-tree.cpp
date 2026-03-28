class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty()) {
            if (q1.front() == nullptr && q2.front() == nullptr) {
                q1.pop();
                q2.pop();
            }else if (q1.front() != nullptr && q2.front()!= nullptr) {
                if (q1.front()->val != q2.front()->val) {
                    return false;
                }
                q1.push(q1.front()->left);
                q1.push(q1.front()->right);
                q2.push(q2.front()->right);
                q2.push(q2.front()->left);
                q1.pop();
                q2.pop();
            }else{
                return false;
            }
        }
        if (q2.empty()) {
            return true;
        }
        return false;

    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left,root->right);
    }
};