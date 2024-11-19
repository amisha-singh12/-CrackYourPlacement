class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;  // To store the previous node
        ListNode* current = head; // To traverse the list

        while (current != nullptr) {
            ListNode* nextNode = current->next; // Save the next node
            current->next = prev;              // Reverse the pointer
            prev = current;                    // Move prev forward
            current = nextNode;                // Move current forward
        }

        return prev; // New head of the reversed list
    }
};
