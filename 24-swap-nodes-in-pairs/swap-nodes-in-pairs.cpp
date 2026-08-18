class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to handle edge cases easily
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Traverse the list while there are at least two nodes left to swap
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Perform the swap
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move prev forward by two nodes for the next pair
            prev = first;
        }
        
        return dummy.next;
    }
};