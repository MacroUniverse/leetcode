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

inline ListNode* slist_split(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    ListNode *head1 = slow->next;
    slow->next = NULL;
    return head1;
}

// merge 2 sorted singly linked list
inline ListNode* slist_merge_sorted(ListNode* a, ListNode* b)
{
    if (a == NULL) return (b);
    if (b == NULL) return (a);
    ListNode *head, *node;
    if (a->val < b->val) {
        head = node = a; a = a->next;
    }
    else {
        head = node = b; b = b->next;
    }
    while (1) {
        if (a == NULL) {
            node->next = b; break;
        }
        if (b == NULL) {
            node->next = a; break;
        }
        if (a->val < b->val) {
            node = (node->next = a); a = a->next;
        }
        else {
            node = (node->next = b); b = b->next;
        }
    }
    return head;
}

/* sorts the linked list by changing next pointers (not data) */
inline void slist_mergesort(ListNode *&headRef)
{
    ListNode* head = headRef;
    if (head == NULL || head->next == NULL)
        return;
    ListNode* head1 = slist_split(head);
    slist_mergesort(head);
    slist_mergesort(head1);
    headRef = slist_merge_sorted(head, head1);
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        slist_mergesort(head);
        return head;
    }
};
