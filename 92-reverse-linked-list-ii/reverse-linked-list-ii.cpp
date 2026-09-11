#include <iostream>

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        ListNode* curr = prev->next;
        ListNode* forward = nullptr;
        ListNode* sub_tail = curr;
        
        for (int i = 0; i <= right - left; ++i) {
            ListNode* next_node = curr->next;
            curr->next = forward;
            forward = curr;
            curr = next_node;
        }
        
        sub_tail->next = curr; 
        prev->next = forward;  
        
        return dummy.next;
    }
};