// Definition for a binary tree node.
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
    // Function to find the lowest common ancestor of the deepest leaves.
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return depthFirstSearch(root).first;
    }

    // Helper function to perform depth-first search.
    // It will return a pair consisting of the lowest common ancestor at the current subtree and the depth of the deepest leaves.
    pair<TreeNode*, int> depthFirstSearch(TreeNode* node) {
        if (!node) {
            // If the node is null, return a pair of nullptr and depth 0.
            return {nullptr, 0};
        }
      
        // Recursively look for deepest leaves in the left and right subtrees.
        auto [leftSubtreeLCA, leftDepth] = depthFirstSearch(node->left);
        auto [rightSubtreeLCA, rightDepth] = depthFirstSearch(node->right);
      
        if (leftDepth > rightDepth) {
            // If the left subtree is deeper, return the left subtree's LCA and depth.
            return {leftSubtreeLCA, leftDepth + 1};
        } else if (leftDepth < rightDepth) {
            // If the right subtree is deeper, return the right subtree's LCA and depth.
            return {rightSubtreeLCA, rightDepth + 1};
        } else {
            // If both subtrees have the same depth, return the current node as the LCA, as both its left and right subtree have the deepest leaves.
            return {node, leftDepth + 1};
        }
    }
};