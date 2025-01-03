class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head; // Slow pointer
        ListNode* fast = head; // Fast pointer

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast) {
                // Step 2: Find the starting node of the cycle
                slow = head; // Move slow pointer to head
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Start of the cycle
            }
        }

        // No cycle
        return NULL;
    }
};

