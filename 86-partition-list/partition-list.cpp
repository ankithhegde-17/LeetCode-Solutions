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
    ListNode* partition(ListNode* head, int x) {
        ListNode a(0), b(0), *p = &a, *q = &b;

        while (head) {
            if (head->val < x) p->next = head, p = p->next;
            else q->next = head, q = q->next;
            head = head->next;
        }

        q->next = nullptr;
        p->next = b.next;
        return a.next;
    }
};