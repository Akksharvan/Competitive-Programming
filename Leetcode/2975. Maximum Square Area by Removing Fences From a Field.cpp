static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    const long long MOD = 1e9 + 7;
    int maximizeSquareArea(int M, int N, vector<int> &A, vector<int> &B) {
        long long R = -1; A.push_back(1); A.push_back(M);
        B.push_back(1); B.push_back(N); unordered_set<int> C, D;
        
        for (int &i : A) for (int &j : A) if (j - i > 0) C.insert(j - i);
        for (int &i : B) for (int &j : B) if (j - i > 0) D.insert(j - i);
        
        
        for (const int &i : C) R = max(R, (D.find(i) != end(D)) ? (long long) i : (long long) -1);
        if (R == -1) return -1; else return (int) ((R * R) % MOD);
    }
};