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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *node1 = list1, *node2 = list2, *head, *tail;
        if (node1 == NULL)
            return node2;
        if (node2 == NULL)
            return node1;     
        if (node1->val <= node2->val) {
            head = tail = node1; node1 = node1->next;
            if (node1 == NULL) {
                tail->next = node2;
                return head;
            }
        }
        else {
            head = tail = node2; node2 = node2->next;
            if (node2 == NULL) {
                tail->next = node1;
                return head;
            }
        }
        while (1) {
            if (node1->val <= node2->val) {
                tail->next = node1;
                tail = node1; node1 = node1->next;
                if (node1 == NULL) {
                    tail->next = node2;
                    return head;
                }
            }
            else {
                tail->next = node2;
                tail = node2; node2 = node2->next;
                if (node2 == NULL) {
                    tail->next = node1;
                    return head;
                }
            }
        }
    }
};
