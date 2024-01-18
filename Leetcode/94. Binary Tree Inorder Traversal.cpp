static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<int> inorderTraversal (TreeNode* R) {
        vector<int> A;
        stack<TreeNode*> B;
		
        while (R || !B.empty()) {
            while (R) B.push(R), R = R -> left;
            R = B.top(); B.pop();

            A.push_back(R -> val);
            R = R -> right;
        }

        return A;
    }
};