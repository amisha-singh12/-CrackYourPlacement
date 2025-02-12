class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) { 
                // No left subtree, visit node and move right
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find inorder predecessor (rightmost node in left subtree)
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    // Create threaded link and visit node
                    pred->right = curr;
                    result.push_back(curr->val); // Visit node before going left
                    curr = curr->left;
                } else {
                    // Remove the threaded link and move right
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};
