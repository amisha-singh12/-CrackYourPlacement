
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false; // No cycle if the list is empty or has only one node
        }

        ListNode* slow = head;       // Slow pointer moves one step at a time
        ListNode* fast = head;       // Fast pointer moves two steps at a time

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Move slow pointer by one step
            fast = fast->next->next; // Move fast pointer by two steps

            if (slow == fast) {
                return true;         // Cycle detected if slow and fast pointers meet
            }
        }

        return false; // No cycle if fast pointer reaches the end
    }
};
