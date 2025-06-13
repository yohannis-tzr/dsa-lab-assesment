#include <functional> // Include the functional header for std::function

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
    void recoverTree(TreeNode* root) {
        TreeNode* previous = nullptr; // Pointer to keep track of the previous node during in-order traversal
        TreeNode* first = nullptr;    // Pointer to the first node that is out of the expected order
        TreeNode* second = nullptr;   // Pointer to the second node that is out of the expected order

        // Function to perform in-order traversal and identify the two nodes that are out of order
        std::function<void(TreeNode*)> inorderTraversal = [&](TreeNode* node) {
            if (!node) return; // If the node is null, return from the function

            inorderTraversal(node->left); // Traverse to the left child
          
            // Check if the previous node's value is greater than the current node's value
            if (previous && previous->val > node->val) {
                // If this is the first occurrence of an out-of-order pair, store the first node
                if (!first) first = previous;
                // In case of second occurrence or adjacent nodes being out of order, store the second node
                second = node;
            }
            previous = node; // Update the previous pointer to the current node

            inorderTraversal(node->right); // Traverse to the right child
        };

        inorderTraversal(root); // Start the in-order traversal from the root

        if (first && second) {
            // Swap the values of the first and second nodes to correct the tree
            std::swap(first->val, second->val);
        }
    }
};