/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
#include <unordered_map>
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //first shallow copy without the random field
        Node* temp = head;
        unordered_map<Node*, Node*> link;
        Node*prev = NULL;
        Node* newHead = NULL;
        //perform copy of value and random field as is
        while(temp != NULL) {
            if (prev==NULL) {
                Node* newNode = new Node(head->val, NULL, head->random);
                prev = newNode;
                newHead = newNode;
            } else {
                prev->next = new Node(temp->val, NULL, temp->random);
                prev = prev ->next;
            }
            temp = temp -> next;
        }
        temp = head;
        Node* temp2 = newHead;
        while(temp != NULL) {
            link[temp] = temp2;
            temp = temp -> next;
            temp2 = temp2->next;
        }
        
        temp2 = newHead;
        while(temp2 != NULL) {
            auto it = link.find(temp2->random);
            if (it != link.end()) {
                temp2->random = it->second;
            } //else error
            temp2 = temp2 -> next;
        }

        return newHead;
    }
};