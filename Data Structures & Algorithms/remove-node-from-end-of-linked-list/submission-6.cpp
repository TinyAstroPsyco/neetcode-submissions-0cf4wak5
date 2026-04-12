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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Traverse through head and - delete the n-th id
        ListNode* dummy = new ListNode(0,head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        int counter = 0;
        while(fast->next != nullptr){
            if(counter < n){
                fast=fast->next;
            }

            else{
                fast = fast->next;
                slow = slow->next;
            }
            counter++;

        }
        // Now the slow ptr is the nth ptr.
        slow->next = slow->next->next;
        return dummy->next;

    }
};
