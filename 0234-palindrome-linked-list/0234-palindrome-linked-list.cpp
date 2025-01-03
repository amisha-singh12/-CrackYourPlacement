class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // Edge case: empty or single-node list
        
        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* nextTemp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextTemp;
        }

        // Step 3: Compare the first and second halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                return false; // Mismatch found
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // If we reach here, the list is a palindrome
        return true;
    }
};
