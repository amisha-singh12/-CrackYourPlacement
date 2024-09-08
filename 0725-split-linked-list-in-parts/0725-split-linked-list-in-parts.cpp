class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Calculate the length of the linked list
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        
        // Step 2: Calculate base size and the number of extra nodes
        int baseSize = length / k;  // Minimum size of each part
        int extraNodes = length % k; // Extra nodes to distribute in the first few parts
        
        // Step 3: Split the list into parts
        vector<ListNode*> result(k, nullptr);
        current = head;
        
        for (int i = 0; i < k && current != nullptr; i++) {
            result[i] = current;
            int currentPartSize = baseSize + (i < extraNodes ? 1 : 0);  // Calculate the size of the current part
            
            // Move to the last node of the current part
            for (int j = 1; j < currentPartSize; j++) {
                current = current->next;
            }
            
            // Detach the current part from the rest of the list
            ListNode* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }
        
        return result;
    }
};
