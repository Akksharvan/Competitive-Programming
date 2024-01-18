class Solution {
public:
    bool isSymmetric (TreeNode* A) {
        if (A == NULL) return 1;
        return B(A -> left, A -> right);
    }

    bool B (TreeNode *C, TreeNode *D) {
        if (C == NULL && D == NULL) return 1;
        else if (C == NULL || D == NULL) return 0;
        else if (C -> val != D -> val) return 0;

        return (B(C -> left, D -> right) && B(C -> right, D -> left));
    }
};