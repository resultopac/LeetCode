#include <stack>
#include <map>
using namespace std;


class Solution {
public:
    void dfs(TreeNode* node,int depth, int& maksDepth, int& sum) {
        if (!node) {
            return;
        }
        if (depth > maksDepth) {
            maksDepth = depth;
            sum = 0;
        }
        if (maksDepth == depth) {
            sum += node->val;
        }

        dfs(node->left,depth+1,maksDepth,sum);
        dfs(node->right,depth+1,maksDepth,sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int maksDepth = 0;
        dfs(root,0,maksDepth,sum);
        return  sum;
    }
};