class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr; // No cycle if list is empty or has only one node
        
        ListNode *slow = head, *fast = head;

        // Step 1: Detect if there is a cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) { // Cycle detected
                ListNode *entry = head;
                
                // Step 2: Find the entry point of the cycle
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                
                return entry; // The start of the cycle
            }
        }

        return nullptr; // No cycle
    }
};
