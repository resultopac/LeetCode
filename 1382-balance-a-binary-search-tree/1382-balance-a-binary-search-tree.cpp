#include <vector>

void addToVector(TreeNode* root, std::vector<int>& vec) {
    if (root == nullptr) {
        return;
    }
    addToVector(root->left,vec);
    vec.push_back(root->val);
    addToVector(root->right,vec);
}

TreeNode* constructTree(TreeNode* root, std::vector<int>& vec) {
    if (vec.empty()) return nullptr;

    int mid = vec.size() / 2;

    if (root == nullptr)
        root = new TreeNode(vec[mid]);
    else
        root->val = vec[mid];

    std::vector<int> leftSlice(vec.begin(), vec.begin() + mid);
    std::vector<int> rightSlice(vec.begin() + mid + 1, vec.end());

    root->left = constructTree(root->left, leftSlice);
    root->right = constructTree(root->right, rightSlice);

    return root;
}


class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> v;
        addToVector(root,v);
        root = constructTree(root,v);
        return root;
    }
};