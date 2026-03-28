class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        stack1.push(root);
        while (!stack1.empty() || !stack2.empty()) {
            vector<int> thisLevel;
            if (!stack2.empty()) {
                while (!stack2.empty()) {
                    if (stack2.top()!=nullptr) {
                        thisLevel.push_back(stack2.top()->val);
                        stack1.push(stack2.top()->right);
                        stack1.push(stack2.top()->left);
                    }
                    stack2.pop();
                }
            }else {
                while (!stack1.empty()) {
                    if (stack1.top() != nullptr) {
                        thisLevel.push_back(stack1.top()->val);
                        stack2.push(stack1.top()->left);
                        stack2.push(stack1.top()->right);
                    }
                    stack1.pop();
                }
            }
            res.push_back(thisLevel);
        }
        res.pop_back();
        return res;
    }
};