class Solution {
public:
    int minDepth (TreeNode* A) {
        if (!A) return 0;

        if (!(A -> left)) return 1 + minDepth(A -> right);
        if (!(A -> right)) return 1 + minDepth(A -> left);
        
        return 1 + min(minDepth(A -> left), minDepth(A -> right));
    }
};