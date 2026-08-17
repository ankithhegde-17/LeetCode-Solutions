/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases easily (e.g., removing the head node)
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Advance the fast pointer n + 1 steps so there is a gap of n nodes between fast and slow
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers until the fast pointer reaches the end of the list
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Skip the target node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Free memory of the deleted node to prevent memory leaks
        delete nodeToDelete;
        
        ListNode* newHead = dummy->next;
        delete dummy; // Free dummy node memory
        
        return newHead;
    }
};