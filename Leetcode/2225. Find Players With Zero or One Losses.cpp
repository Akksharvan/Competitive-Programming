static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<vector<int>> findWinners (vector<vector<int>> &A) {
        vector<vector<int>> R(2); unordered_map<int, int> B;
        for (vector<int> &i : A) B[i[0]] = B[i[0]], B[i[1]]++;

        for (const pair<int, int> &i : B) {
            if (i.second == 0) R[0].push_back(i.first);
            else if (i.second == 1) R[1].push_back(i.first);
        }

        sort(begin(R[0]), end(R[0]));
        sort(begin(R[1]), end(R[1]));

        return R;
    }
};