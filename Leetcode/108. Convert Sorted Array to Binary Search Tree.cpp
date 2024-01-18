class Solution {
public:
    TreeNode* sortedArrayToBST (vector<int>& A) {
        return B(A, 0, size(A) - 1);
    }

    TreeNode* B (vector<int> &A, int L, int H) {
        if (L <= H) {
            int M = L + (H - L) / 2;
            TreeNode *C = new TreeNode(A[M]);
            
            C -> left = B(A, L, M - 1);
            C -> right = B (A, M + 1, H);

            return C;
        }

        return NULL;
    }
};