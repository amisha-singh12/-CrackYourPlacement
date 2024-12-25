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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // Dummy node to store result
        ListNode* current = dummy; // Pointer to traverse the result list
        int carry = 0; // Carry to keep track of overflow

        // Traverse both linked lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with carry value from previous step
            if (l1 != nullptr) {
                sum += l1->val; // Add value from l1
                l1 = l1->next; // Move to next node in l1
            }
            if (l2 != nullptr) {
                sum += l2->val; // Add value from l2
                l2 = l2->next; // Move to next node in l2
            }

            carry = sum / 10; // Update carry (sum divided by 10)
            current->next = new ListNode(sum % 10); // Create a new node with current digit
            current = current->next; // Move to the new node
        }

        return dummy->next; // Return the next of dummy node, which is the start of the result list
    }
};