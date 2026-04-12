/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> database;
        Node* base = head;

        while(base != nullptr){
            database[base] = new Node(base->val);
            base = base->next;
        }

        // Now we will have a hashmap of values so
        // We build a new one now.
        Node* copy;
        base = head;
        while(base !=nullptr){
            copy = database[base];
            copy->next = database[base->next];
            copy->random = database[base->random];
            base = base->next;
        }
        return database[head];
    }
};




