class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }

        Node *curr = head;
        while (curr != nullptr) {
            if (curr->child != nullptr) {
                // step 1) to flatten the child nodes recursively
                Node *next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = nullptr;

                // step 2) find tail of flattened list
                while (curr->next != nullptr) {
                    curr = curr->next;
                }

                // step 3) Attach next ptr with tail
                if (next != nullptr) {
                    curr->next = next;
                    next->prev = curr;
                }

            }

            curr = curr->next;
        }

        return head;
        
    }
};
