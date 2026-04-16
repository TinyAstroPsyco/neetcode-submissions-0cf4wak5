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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Logic
        // Walk k steps, then store the k+1 node in reserve;
        // Revere the list, now, for the checkpoint node, assing the next node as reserve.
        // Repeat

        // For the reverse logic
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        ListNode* k_node = nullptr;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = head;
        
        ListNode* current = head;
        ListNode* checkpoint = current;
        bool firstUpdate = true;

        ListNode* grouptail = current;
        
        while(true){
            k_node = current;
            if(current == nullptr) return dummy->next;
            // return k_node;
            for(int i = 0; i< k-1; i++){

                if(k_node->next != nullptr){
                    k_node = k_node->next;
         
                }
                else{
                    return dummy->next;
                }
            }
            tail = k_node->next; // tail is 4 now.
            int counter = 0;
            prev = nullptr;
            grouptail = current;

            while(counter < k){
                // if(counter == 0) hd = current;
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                counter++;
            }
        
            // Reversal happened, now prev is reversed node
            if(firstUpdate) {
                dummy->next = prev;
                firstUpdate = false;
                
            }
            else {
               
                checkpoint->next = prev;  // ✅ connect previous tail to current head
            }
            grouptail->next = tail;
            checkpoint = grouptail;
            
        }

    }
};
