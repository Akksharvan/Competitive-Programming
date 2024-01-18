static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int rangeSumBST (TreeNode* A, int L, int H) {
        stack<TreeNode*> B; 
        int R = 0; B.push(A);

        while (!B.empty()) {
            TreeNode* C = B.top(); B.pop();
            if (C -> val >= L && C -> val <= H) R += C -> val;

            if (C -> left) B.push(C -> left);
            if (C -> right) B.push(C -> right);
        }

        return R;
    }
};