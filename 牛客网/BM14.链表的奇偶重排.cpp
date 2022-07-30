/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode*head1 = head->next, *node = head, *node1 = head1;
        if (head1 == NULL)
            return head;
        bool node_is_odd = true;
        while (node1->next != NULL) {
            node->next = node1->next;
            node = node1; node1 = node1->next;
            node_is_odd = !node_is_odd;
        }
        if (node_is_odd)
            node->next = head1;
        else {
            node->next = NULL;
            node1->next = head1;
        }
        return head;
    }
};
