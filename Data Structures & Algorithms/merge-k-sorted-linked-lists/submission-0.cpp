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
private:
        struct comparee
        {
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, comparee> min_heap;

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {


        // Now we will empty the vector
        for(int i = 0; i<lists.size(); i++){
            if(lists[i]) min_heap.push(lists[i]);
        }

        // Now we need to bring it out.
        ListNode* head = new ListNode(0);
        ListNode* dummy = new ListNode(0);\
        dummy->next = head;
        while(!min_heap.empty()){
            ListNode* current = min_heap.top();
            min_heap.pop();
            head->next = current;
            head = head->next;
            if(current->next) min_heap.push(current->next);
        }
        return dummy->next->next;
    }
};
