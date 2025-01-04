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
    ListNode* rotateRight(ListNode* head, int k) {
       if( !head || !head -> next  || k == 0 ) {
        return head;
       }
        // finding length of linked list
        int n = 1;
        ListNode* temp = head;
        while (temp->next != nullptr) {
        temp = temp->next;
        n++;
}

        //   normalizing k
        k = k%n ;
        if(k == 0 ) return head;

        //making a circluar ll
        temp ->next = head;

        //  pointing new tail pos 
        int tailpos = n -k -1;
        temp = head;
        for(int i= 0 ; i < tailpos ; i++){
            temp = temp -> next; 
        }
        ListNode* newhead =  temp -> next ;
        temp ->next = nullptr;

        return newhead;
    }
};