static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    void merge (vector<int> &A, int N, vector<int> &B, int M) {
        vector<int> C;
        int P1 = 0, P2 = 0;

        while (P1 < N) {
            while (P2 < M && B[P2] <= A[P1]) C.push_back(B[P2]), P2++;
            C.push_back(A[P1]), P1++;
        }

        while (P2 < M) C.push_back(B[P2]), P2++;
        A = C;
    }
};