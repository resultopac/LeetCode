class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> currQ = q;
            queue<TreeNode*> nextLevel;
            vector<int> thisLevel ;
            while (!currQ.empty()) {
                if (currQ.front() != nullptr) {
                    thisLevel.push_back(currQ.front()->val);
                    nextLevel.push(currQ.front()->left);
                    nextLevel.push(currQ.front()->right);
                }
                currQ.pop();
            }
            q = nextLevel;
            res.push_back(thisLevel);
        }
        res.pop_back();
        return res;

    }
};