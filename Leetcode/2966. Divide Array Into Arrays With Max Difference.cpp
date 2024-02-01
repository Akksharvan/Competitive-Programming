static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    bool F (vector<vector<int>> &R, int K) {
        for (auto &i : R) if (*max_element(begin(i), end(i)) - *min_element(begin(i), end(i)) > K) return 0;
        return 1;
    }

    vector<vector<int>> divideArray(vector<int> &A, int K) {
        sort(begin(A), end(A)); int N = size(A); vector<vector<int>> R(N / 3);
        for (int i = 0; i < N; i += 3) R[i / 3].push_back(A[i]), R[i / 3].push_back(A[i + 1]), R[i / 3].push_back(A[i + 2]);

        if (!F(R, K)) { R.clear(); return R; }
        else return R;
    }
};