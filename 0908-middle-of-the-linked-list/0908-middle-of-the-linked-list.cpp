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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;  // Pointer for fast traversal
        ListNode* slow = head;  // Pointer for slow traversal

        // Traverse the list until fast reaches the end
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         // Move slow one step
            fast = fast->next->next;   // Move fast two steps
        }

        return slow;  // Slow pointer will be at the middle node
    }
};
