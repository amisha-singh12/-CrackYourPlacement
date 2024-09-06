#include <unordered_set>
#include <vector>

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        // Step 1: Create a hash set for the values in nums
        std::unordered_set<int> toRemove(nums.begin(), nums.end());

        // Step 2: Initialize a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* current = dummy;

        // Step 3: Traverse the list and remove nodes whose values are in the set
        while (current->next != nullptr) {
            if (toRemove.find(current->next->val) != toRemove.end()) {
                // Remove the node
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free the memory
            } else {
                current = current->next;
            }
        }

        // Step 4: Return the new head of the list
        return dummy->next;
    }
};
