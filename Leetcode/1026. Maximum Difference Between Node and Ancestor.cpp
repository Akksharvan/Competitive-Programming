static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int maxAncestorDiff(TreeNode* A) {
        stack<pair<TreeNode*, pair<int, int>>> S; int R = 0;

        if (A -> left) S.push({A -> left, {A -> val, A -> val}});
        if (A -> right) S.push({A -> right, {A -> val, A -> val}});

        while (!S.empty()) {
            pair<TreeNode*, pair<int, int>> B = S.top(); S.pop();
            R = max(R, max(abs(B.first -> val - B.second.first), abs(B.first -> val - B.second.second)));

            B.second.first = min(B.second.first, B.first -> val);
            B.second.second = max(B.second.second, B.first -> val);

            if (B.first -> left) S.push({B.first -> left, B.second});
            if (B.first -> right) S.push({B.first -> right, B.second});
        }

        return R;
    }
};