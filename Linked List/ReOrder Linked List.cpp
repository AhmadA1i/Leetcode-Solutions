class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second = slow->next;
        ListNode *prev = slow->next = nullptr;
        while(second != nullptr) {
            ListNode *temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        ListNode *first = head;
        second = prev;
        while (second != nullptr) {
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;

        }
        
    }
};
