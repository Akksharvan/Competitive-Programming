#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct SegTree {
    int N; vector<long long> A;
    SegTree (int S, vector<long long> &B) { N = S, A.assign(2 * N, 0); for (int i = 0; i < (int) size(B); i++) UPDATE(i, B[i]); }
 
    long long SUM (int L, int R) { long long S = 0; for (L += N, R += N; L <= R; L /= 2, R /= 2) { S += ((L & 1) ? A[L++] : 0), S += (!(R & 1) ? A[R--] : 0); } return S; }
    void UPDATE (int U, int V) { for (A[U + N] = V, U = ((U + N) / 2); U >= 1; U /= 2) A[U] = A[2 * U] + A[2 * U + 1]; }
};

int main() {
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<long long> A, B(2 * N + 2);
    
    for (int i = 0; i < N; i++) {
        int L, R; cin >> L >> R;
        A.push_back(L); B[L]++; B[R + 1]--;
    }

    for (int i = 1; i <= 2 * N + 1; i++) B[i] += B[i - 1];
    SegTree S = SegTree(2 * N + 2, B);

    vector<long long> C(N); C[0] = 1;
    for (long long i = 1; i < N; i++) C[i] = (C[i - 1] * 2) % MOD;

    long long R = 0;
    sort(begin(A), end(A));

    for (long long &i : A) {
        int X = N - S.SUM(i, i);
        R += C[X]; R %= MOD;
    }

    cout << R << "\n";
 	return 0;
}