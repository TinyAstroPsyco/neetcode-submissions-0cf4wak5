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
    bool hasCycle(ListNode* head) {
        // Lets make a hash table to remember the visited node
        unordered_set<ListNode* > database;
        bool present = false;
        while(present == false && head != nullptr){
            if(database.count(head)) return true;
            else{
                database.insert(head);
            }
            head = head->next;
        }
        return false;
    }
};
