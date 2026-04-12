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
        // We will go to the end of the lists
        
        // (while l1 == nullptr && l2 == nullptr){

        // }
        
        int a = 0;
        int b = 0;
        int carry = 0;
        ListNode* dummy = new ListNode(0);
   

        ListNode* sum = dummy;
        while(l1 != nullptr || l2 != nullptr || carry){
            a = (l1 != nullptr) ? l1->val : 0;
            b = (l2 != nullptr) ? l2->val : 0;
            int c = a + b + carry;
            sum->next = new ListNode(c % 10);
            carry = c / 10;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;  
            sum = sum->next;
        }
        return dummy->next;


    }
};
