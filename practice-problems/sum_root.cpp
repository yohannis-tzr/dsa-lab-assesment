// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructor initializes current node and its children to default (no children and value 0).
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // Constructor initializes current node with a value and sets children to default (no children).
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor initializes current node with a value and left and right children.
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        // Recursive function to traverse the tree and calculate the sum.
        // It carries two parameters: the current node and the sum calculated so far.
        std::function<int(TreeNode*, int)> depthFirstSearch = [&](TreeNode* node, int currentSum) -> int {
            // Base case: if the current node is null, return 0 as there's nothing to add.
            if (!node) return 0;
            // Update current sum by appending the current node's value.
            currentSum = currentSum * 10 + node->val;
            // If at a leaf node, return the current sum.
            if (!node->left && !node->right) return currentSum;
            // Recursively call the function for left and right children, and return their sum.
            return depthFirstSearch(node->left, currentSum) + depthFirstSearch(node->right, currentSum);
        };
        // Start the depth first search with the root node and initial sum of 0.
        return depthFirstSearch(root, 0);
    }
};