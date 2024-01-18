class Solution {
public:
    bool hasCycle(ListNode *A) {
        if (!A) return 0;
        ListNode *B = A, *C = A;

        while (B != NULL && B -> next != NULL) {
            B = B -> next -> next; C = C -> next;
            if (B == C) return 1;
        }

        return 0;
    }
};