class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* small = head;
        ListNode* big = head;
        
        while(small != NULL && big != NULL) {
            small = small->next;
            big = big->next;
            if (big == NULL) break;
            big = big -> next;
            if (small == big) return true;
        }
        return false;
    }
};