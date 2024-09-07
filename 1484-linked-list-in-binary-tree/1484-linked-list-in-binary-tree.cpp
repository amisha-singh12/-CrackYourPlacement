/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Helper function to match the linked list and the tree path
    bool matchPath(ListNode* head, TreeNode* root) {
        // If the linked list is null, it means we've matched all nodes successfully
        if (head == nullptr) return true;
        // If the tree node is null, but we haven't exhausted the linked list, return false
        if (root == nullptr) return false;
        // If the values don't match, return false
        if (head->val != root->val) return false;
        // Recursively check the left and right subtrees
        return matchPath(head->next, root->left) || matchPath(head->next, root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        // If the binary tree is null, we cannot match anything
        if (root == nullptr) return false;
        // Check if the current node starts a valid path or continue searching in the left and right subtrees
        return matchPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
