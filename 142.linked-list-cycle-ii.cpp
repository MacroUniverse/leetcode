/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> uset;
        while (head) {
            if (uset.count(head))
                return head;
            uset.insert(head);
            head = head->next;
        }
        return NULL;
    }
};


// solution 2 (fast-slow pointers)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *p = head, *q = head;
        do {
            q = q->next;
            if (q == NULL) return NULL;
            q = q->next;
            if (q == NULL) return NULL;
            p = p->next;
        }
        while (p != q);
        while (head != p) {
            head = head->next;
            p = p->next;
        }
        return p;
    }
};
