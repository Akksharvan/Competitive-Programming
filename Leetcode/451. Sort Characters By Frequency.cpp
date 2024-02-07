static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    string frequencySort (string S) {
        map<int, int> A; for (char &c: S) A[c]++;
        vector<pair<int, int>> B; for (auto &[i, j] : A) B.push_back({j, i});

        sort(rbegin(B), rend(B));
        string R; for (auto &[i, j] : B) for (int k = 0; k < i; k++) R += ((char) j);

        return R;
    }
};