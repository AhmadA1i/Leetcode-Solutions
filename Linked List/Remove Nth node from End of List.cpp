class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            // Dummy node simplifies edge cases
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Move first to the end, maintaining the gap
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Delete target node
        ListNode* temp = second->next;
        second->next = temp->next;
        delete temp;

        // Update head
        head = dummy->next;
        delete dummy;

        return head;
    }
};
