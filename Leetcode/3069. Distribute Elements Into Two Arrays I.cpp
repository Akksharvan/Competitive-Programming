static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<int> resultArray (vector<int> &A) {
        vector<int> B, C; B.push_back(A[0]), C.push_back(A[1]);
        for (int i = 2; i < size(A); i++) { if (B.back() > C.back()) B.push_back(A[i]); else C.push_back(A[i]); }
        
        for (auto &i : C) B.push_back(i);
        return B;
    }
};