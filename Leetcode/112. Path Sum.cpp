class Solution {
public:
    bool hasPathSum (TreeNode* A, int T) {
        if (!A) return 0;
        T -= A -> val;

        if (!T && !(A -> left) && !(A -> right)) return 1;
        return (hasPathSum(A -> left, T) || hasPathSum(A -> right, T));
    }
};