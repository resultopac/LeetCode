class Solution {
public:

    void helper(TreeNode* root, vector<int>& counter, int& res, int oddCount) {
        counter[root->val]++;
        if (counter[root->val] % 2 == 1) {
            oddCount++;
        }else{
            oddCount--;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (oddCount == 1 || oddCount == 0) {
                res++;
            }
        }
        if (root->left != nullptr) {
            helper(root->left,counter,res,oddCount);
        }
        if (root->right != nullptr) {
            helper(root->right,counter,res,oddCount);
        }
        counter[root->val]--;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> counter (10,0);
        int res = 0;
        helper(root,counter,res,0);
        return res;
    }
};