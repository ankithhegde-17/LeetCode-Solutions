class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;
        
        while (true) {
            // Check if there are at least k nodes remaining
            ListNode* cursor = prevGroupTail;
            for (int i = 0; i < k; ++i) {
                cursor = cursor->next;
                if (!cursor) return dummy.next; // Fewer than k nodes left, leave as is
            }
            
            ListNode* groupStart = prevGroupTail->next;
            ListNode* nextGroupHead = cursor->next;
            
            // Reverse the k nodes
            ListNode* prev = nextGroupHead;
            ListNode* curr = groupStart;
            while (curr != nextGroupHead) {
                ListNode* nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }
            
            // Connect the reversed group back to the list
            prevGroupTail->next = prev;
            prevGroupTail = groupStart; // groupStart is now the tail of the reversed group
        }
        
        return dummy.next;
    }
};