class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr; // If either list is empty, return nullptr.

        // Get the lengths of both lists.
        ListNode *currentA = headA;
        ListNode *currentB = headB;
        int lenA = 0, lenB = 0;

        while (currentA) {
            lenA++;
            currentA = currentA->next;
        }

        while (currentB) {
            lenB++;
            currentB = currentB->next;
        }

        // Equalize the starting point for both lists.
        currentA = headA;
        currentB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                currentA = currentA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; i++) {
                currentB = currentB->next;
            }
        }

        // Move both pointers simultaneously until they meet or reach the end.
        while (currentA && currentB) {
            if (currentA == currentB) {
                return currentA; // Intersection point found.
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }

        return nullptr; // No intersection.
    }
};
