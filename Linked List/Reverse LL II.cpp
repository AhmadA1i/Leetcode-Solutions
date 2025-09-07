class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *leftPrev = &dummy;
        ListNode *curr = head;

        for (int i = 0; i < left - 1; i++) {
            leftPrev = curr;
            curr = curr->next;
        }

        ListNode *prev = nullptr;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode *tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }

        leftPrev->next->next = curr;
        leftPrev->next = prev;

        return dummy.next;

    }
};
