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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        size_t base = 1;
        size_t s1 = 0, s2 = 0;

        int sum = 0;
        sum += l1->val + l2->val;
        cout << l1->val << "  " << l2->val << endl;
        l1 = l1->next; l2 = l2->next;
        ListNode *l3 = new ListNode(sum%10);
        ListNode *p = l3;
        sum /= 10;
        
        while (true) {
            if (l1 != NULL) {
                if (l2 != NULL) {
                    sum += l1->val + l2->val;
                    cout << l1->val << "  " << l2->val << endl;
                    l1 = l1->next; l2 = l2->next;
                    p->next = new ListNode(sum%10);
                    p = p->next;
                    sum /= 10;
                }
                else {
                    sum += l1->val;
                    cout << l1->val << endl;
                    l1 = l1->next;
                    p->next = new ListNode(sum%10);
                    p = p->next;
                    sum /= 10;
                }
            }
            else {
                if (l2 != NULL) {
                    sum += l2->val;
                    cout << "     " << l2->val << endl;
                    l2 = l2->next;
                    p->next = new ListNode(sum%10);
                    p = p->next;
                    sum /= 10;
                }
                else {
                    break;
                }
            }
        }
        if (sum > 0) {
            p->next = new ListNode(sum);
        }
        return l3;
    }
};
