class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the starting point of the merged list
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        // Traverse both lists while neither is empty
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        // Attach the remaining nodes from whichever list is still left
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }
        
        // Return the merged list, skipping the initial dummy node
        return dummy.next;
    }
};