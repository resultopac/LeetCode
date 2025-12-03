#include <stack>
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        std::stack<TreeNode*> s;
        int sum = 0;
        s.push(root);
        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            if (curr->val >= low && curr->val <= high) {
                sum+= curr->val;
            }
            if (curr->left != nullptr) {
                s.push(curr->left);
            }
            if (curr->right != nullptr) {
                s.push(curr->right);
            }
        }
        return sum;
    }
};