static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    bool F (vector<int> &A) {
        int R = 0; for (int &i : A) R += (i & 1);
        if (accumulate(begin(A), end(A), 0) & 1) return (R == 1);
        else return (R == 0);
    }
    int pseudoPalindromicPaths (TreeNode* RT) {
        int R = 0; stack<pair<TreeNode*, vector<int>>> S;
        vector<int> A(10); S.push({RT, A}); while (!S.empty()) {
            TreeNode *B = S.top().first; vector<int> C = S.top().second;
            S.pop(); C[B -> val]++; if (!(B -> left) && !(B -> right)) R += F(C);

            if (B -> left) S.push({B -> left, C});
            if (B -> right) S.push({B -> right, C});
        }

        return R;
    }
};