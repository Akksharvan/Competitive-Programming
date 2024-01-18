static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int amountOfTime (TreeNode* R, int A) {
        vector<vector<int>> B(1e5 + 1);
        stack<TreeNode*> S; S.push(R);

        while (!S.empty()) {
            TreeNode* C = S.top(); S.pop();

            if (C -> left) {
                B[C -> val].push_back(C -> left -> val);
                B[C -> left -> val].push_back(C -> val);

                S.push(C -> left);
            }

            if (C -> right) {
                B[C -> val].push_back(C -> right -> val);
                B[C -> right -> val].push_back(C -> val);

                S.push(C -> right);
            }
        }

        vector<bool> V(1e5 + 1); int D = 0;
        stack<pair<int, int>> T; T.push({A, 0});

        while (!T.empty()) {
            pair<int, int> C = T.top(); T.pop();
            V[C.first] = 1; D = max(D, C.second);

            for (int &i : B[C.first]) {
                if (V[i]) continue;
                T.push({i, C.second + 1});
            }
        }

        return D;
    }
};