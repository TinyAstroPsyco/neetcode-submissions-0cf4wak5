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
    void reorderList(ListNode* head) {
        // Okay lets find the middle first
        ListNode* a = head;
        ListNode* b = head;

        while(b->next != nullptr && b->next->next != nullptr){
            a = a->next;
            b = b->next->next;
        } 
        // Now our a will be the middle point value.
        // Now I will reverse the list
        ListNode* second = a->next;
        a->next = nullptr; //Cutting off the link at the center node
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* current = second;

        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        second = prev;

        // Now we will have 2 things to start with, head and current. Now we will have to alternatively join them
        ListNode* first = head;
        while(second != nullptr){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
            
            
        }
 
    }
};
