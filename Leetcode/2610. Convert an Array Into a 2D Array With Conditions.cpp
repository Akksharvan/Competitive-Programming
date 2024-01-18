static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<vector<int>> findMatrix (vector<int> &A) {
        unordered_map<int, int> B; for (int &i : A) B[i]++;
        int C = 0; vector<vector<int>> R;

        for (const pair<int, int> &i : B) {
            for (int j = 0; j < i.second; j++) {
                if (j == C) R.push_back({i.first}), C++;
                else R[j].push_back(i.first);
            }
        }

        return R;
    }
};