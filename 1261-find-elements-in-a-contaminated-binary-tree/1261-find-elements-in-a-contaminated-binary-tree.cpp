class FindElements {
public:

    TreeNode* rootNode;

    FindElements(TreeNode* root) {
        rootNode = root;
        rootNode->val = 0;
        std::stack<TreeNode*> stack;
        stack.push(rootNode);
        while (!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();
            if (curr->left) {
                curr->left->val = curr->val*2+1;
                stack.push(curr->left);
            }
            if (curr->right) {
                curr->right->val = curr->val*2+2;
                stack.push(curr->right);
            }
        }
    }

    bool find(int target) {
        std::stack<TreeNode*> stack;
        stack.push(rootNode);
        while (!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();
            if (curr->val == target) {
                return true;
            }
            if (curr->left) {
                stack.push(curr->left);
            }
            if (curr->right) {
                stack.push(curr->right);
            }
        }
        return false;
    }
};