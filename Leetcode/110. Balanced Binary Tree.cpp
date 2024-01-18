class Solution {
public:
    bool B;

    bool isBalanced (TreeNode* A) {
        B = 1; int X = F(A);
        return B;
    }

    int F (TreeNode* A) {
        if (!A || !B) return 0;
        int L = F(A -> left), R = F(A -> right);

        if (abs(L - R) > 1) B = 0;
        return 1 + max(L, R);
    }
};