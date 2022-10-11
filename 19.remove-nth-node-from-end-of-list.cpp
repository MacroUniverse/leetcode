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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node = slist_rlocate(head, n+1);
        if (node == NULL)
            return head->next;
        node->next = node->next->next;
        return head;
    }

    inline ListNode *slist_rlocate(ListNode *node, int ind)
    {
        ListNode *node0 = node;
        for (int i = 0; i < ind; ++i) {
            if (node == NULL) return NULL;
            node = node->next;
        }
        while (node)
            node = node->next, node0 = node0->next;
        return node0;
    }
};
