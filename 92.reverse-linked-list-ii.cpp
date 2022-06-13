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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *L1 = NULL, *R1 = NULL, *last = NULL, *node = head, *next = head->next;
        if (left == right)
            return head;
        if (left > 1) {
            for (int i = 2; i < left; ++i)
                node = node->next;
            L1 = node; node = node->next;
            // node at 1st blue
        }
        next = node->next;
        for (int i = left+1; i <= right; ++i) {
            last = node; node = next; next = node->next;
            node->next = last;
        }
        // node at last blue
        if (L1 == NULL) {
            head->next = next;
            head = node;
        }
        else {
            L1->next->next = next;
            L1->next = node;
        }
        return head;
    }
};
