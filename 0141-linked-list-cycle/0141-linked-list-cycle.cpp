/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Create an unordered_map to store the addresses of visited nodes
        std::unordered_map<ListNode*, bool> visited;

        // Traverse the linked list
        ListNode* current = head;
        while (current != nullptr) {
            // If the current node address is already in the map, there's a cycle
            if (visited.find(current) != visited.end()) {
                return true;
            }
            // Mark the current node as visited
            visited[current] = true;
            current = current->next;
        }

        // If traversal completes without finding a cycle, return false
        return false;
    }
};