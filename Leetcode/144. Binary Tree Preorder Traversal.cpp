class Solution {
public:
    vector<int> preorderTraversal(TreeNode* A) {
        vector<int> R; if (!A) return R;
        else R.push_back(A -> val);

        stack<TreeNode*> DFS;

        if (A -> right != NULL) DFS.push(A -> right);
        if (A -> left != NULL) DFS.push(A -> left);

        while (!DFS.empty()) {
            TreeNode *B = DFS.top();
            DFS.pop(); R.push_back(B -> val);

            if (B -> right != NULL) DFS.push(B -> right);
            if (B -> left != NULL) DFS.push(B -> left);
        }

        return R;
    }
};