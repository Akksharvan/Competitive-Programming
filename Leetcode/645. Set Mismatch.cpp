static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<int> findErrorNums (vector<int> &A) {
        vector<int> R(2); unordered_set<int> B; long long S = (size(A) * (size(A) + 1)) / 2;
        for (int i : A) R[0] = (B.count(i) ? i : R[0]), B.insert(i), S -= i; R[1] = S + R[0];

        return R;
    }
};