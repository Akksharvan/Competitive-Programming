static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    string frequencySort (string S) {
        array<pair<int, int>, 256> A{}; for (auto i : S) A[i].first++, A[i].second = i;
        sort(rbegin(A), rend(A)); string R; for (auto &[i, j] : A) for (int k = 0; k < i; k++) R += ((char) j);

        return R;
    }
};