class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node to simplify edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            // Check if there are at least k nodes remaining
            ListNode* kthNode = prevGroupEnd;
            for (int i = 0; i < k; ++i) {
                kthNode = kthNode->next;
                if (!kthNode) return dummy.next;
            }

            // Reverse k nodes
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kthNode->next;
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;

            for (int i = 0; i < k; ++i) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect reversed group with previous and next groups
            prevGroupEnd->next = kthNode;
            prevGroupEnd = groupStart;
        }
    }
};
