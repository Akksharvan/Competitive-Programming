class Solution {
public:
    ListNode* deleteDuplicates (ListNode* A) {
        ListNode* B = A;
        while (B && B -> next) {
            if (B -> next -> val == B -> val) { B -> next = B -> next -> next; continue; }
            B = B -> next;
        }

        return A;
    }
};