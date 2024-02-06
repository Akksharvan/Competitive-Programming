static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<vector<string>> groupAnagrams (vector<string> &A) {
        map<array<int, 26>, int> B; vector<vector<string>> R;
        int C = 0, N = size(A); for (int i = 0; i < N; i++) {
            array<int, 26> D{}; for (auto &c : A[i]) D[c - 97]++;
            if (B.count(D)) R[B[D]].push_back(A[i]); else B[D] = C, C++, R.push_back({A[i]});
        }

        return R;
    }
};