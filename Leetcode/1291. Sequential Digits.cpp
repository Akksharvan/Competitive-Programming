static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<int> sequentialDigits (int L, int H) {
        vector<int> R; string S = "123456789";
        for (int i = 0; i < 9; i++) for (int j = i; j < 9; j++) {
            int N = stoi(S.substr(i, (j - i) + 1));
            if (L <= N && N <= H) R.push_back(N);
        }

        sort(begin(R), end(R));
        return R;
    }
};