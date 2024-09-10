#include <algorithm> // for std::gcd

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head; // If the list has less than two nodes, return as is.

        ListNode* current = head;

        // Traverse the list
        while (current && current->next) {
            int gcdValue = std::gcd(current->val, current->next->val); // Calculate GCD of current and next node values
            ListNode* newNode = new ListNode(gcdValue); // Create a new node with the GCD value
            newNode->next = current->next; // Link the new node to the next node
            current->next = newNode; // Link the current node to the new node
            current = newNode->next; // Move to the next original node
        }

        return head;
    }
};
