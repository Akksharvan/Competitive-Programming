static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    bool uniqueOccurrences(vector<int> &A) {
        unordered_map<int, int> B; for (int &i : A) B[i]++;
        unordered_set<int> C; for (auto &[i, j] : B) { if (C.count(j)) { return 0; } C.insert(j); } return 1;
    }
};