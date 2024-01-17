#include <bits/stdc++.h>
using namespace std;
 
struct SegTree {
    int N; vector<long long> A;
    SegTree (int S, vector<long long> &B) { N = S, A.assign(2 * N, LLONG_MAX); for (int i = 0; i < (int) size(B); i++) UPDATE(i, B[i]); }
 
    long long MIN (int L, int R) { long long S = LLONG_MAX; for (L += N, R += N; L <= R; L /= 2, R /= 2) { S = ((L & 1) ? min(S, A[L++]) : S), S = (!(R & 1) ? min(S, A[R--]) : S); } return S; }
    void UPDATE (int U, int V) { for (A[U + N] = V, U = ((U + N) / 2); U >= 1; U /= 2) A[U] = min(A[2 * U], A[2 * U + 1]); }
};
 
int main() {
	ios::sync_with_stdio(0); 
	cin.tie(nullptr);
 
	int N, Q; cin >> N >> Q;
	vector<long long> A(N); for (long long &i : A) cin >> i; SegTree B(N, A);
 
	while (Q--) {
		int T; cin >> T; if (T == 1) { int K, U; cin >> K >> U; B.UPDATE(K - 1, U); }
		else if (T == 2) { int L, R; cin >> L >> R; cout << B.MIN(L - 1, R - 1) << "\n"; }
	}
 
	return 0;
}