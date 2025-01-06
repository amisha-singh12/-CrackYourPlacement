class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; // If the list is empty, return null.

        // Step 1: Create a copy of each node and insert it after the original node.
        Node* current = head;
        while (current) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        // Step 2: Assign random pointers for the copied nodes.
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next; // Move to the next original node.
        }

        // Step 3: Detach the copied list from the original list.
        Node* dummyHead = new Node(0);
        Node* copyCurrent = dummyHead;
        current = head;
        while (current) {
            copyCurrent->next = current->next; // Link to copied node.
            copyCurrent = copyCurrent->next;  // Move the copied list forward.
            current->next = current->next->next; // Restore the original list.
            current = current->next; // Move the original list forward.
        }

        return dummyHead->next; // Return the head of the copied list.
    }
};
