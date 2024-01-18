static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    bool leafSimilar (TreeNode* R1, TreeNode* R2) {
        vector<int> A, B; stack<TreeNode*> C, D;
        C.push(R1); D.push(R2);

        while (!C.empty()) {
            TreeNode* E = C.top(); C.pop();
            if (!(E -> left) && !(E -> right)) A.push_back(E -> val);

            if (E -> right) C.push(E -> right);
            if (E -> left) C.push(E -> left);
        }

        while (!D.empty()) {
            TreeNode* E = D.top(); D.pop();
            if (!(E -> left) && !(E -> right)) B.push_back(E -> val);

            if (E -> right) D.push(E -> right);
            if (E -> left) D.push(E -> left);
        }

        return (A == B);
    }
};