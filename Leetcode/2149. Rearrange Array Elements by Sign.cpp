static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<int> rearrangeArray (vector<int> &A) {
        vector<vector<int>> B(2); for (auto &i : A) B[(i >= 0) ? 0 : 1].push_back(i);
        reverse(begin(B[0]), end(B[0])); reverse(begin(B[1]), end(B[1])); A.clear();
        
        while (!B[0].empty()) {
            A.push_back(B[0].back()), B[0].pop_back();
            A.push_back(B[1].back()), B[1].pop_back();
        }

        return A;
    }
};