/**
 * Definition for a binary tree node.
 */

#include <algorithm>
#include <tuple>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return std::get<1>(getDiameterAndDepth(root));
    }
private:
    std::tuple<int, int> getDiameterAndDepth(const TreeNode *const root) {
        if (root == NULL) return std::make_tuple(-1, -1);

        int d_l, d_r, di_l, di_r;
        std::tie(d_l, di_l) = getDiameterAndDepth(root->left);
        std::tie(d_r, di_r) = getDiameterAndDepth(root->right);
        int depth = std::max(d_l, d_r) + 1;
        int diameter = std::max(d_l + d_r + 2, std::max(di_l, di_r));
        return std::make_tuple(depth, diameter);
    }
};