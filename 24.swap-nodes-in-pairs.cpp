class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *p1 = head, *p2 = p1->next;
        if (p2 == NULL)
            return p1;
        ListNode* ret = p2;
        while (true) {
            ListNode* p3 = p2->next;
            p2->next = p1;
            if (p3 == NULL) {
                p1->next = NULL;
                return ret;
            }
            ListNode* p4 = p3->next;
            if (p4 == NULL) {
                p1->next = p3;
                return ret;
            }
            p1->next = p4;
            p1 = p3; p2 = p4;
        }
    }
};
