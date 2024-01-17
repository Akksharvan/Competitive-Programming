#include <bits/stdc++.h>
using namespace std;
 
struct SegTree {
    int N; vector<long long> A;
    SegTree (int S, vector<long long> &B) { N = S + 1, A.assign(2 * N, 0); for (int i = 0; i < (int) size(B); i++) UPDATE(i, B[i]); }
 
    long long SUM (int L, int R) { long long S = 0; for (L += N, R += N; L <= R; L /= 2, R /= 2) { S += ((L & 1) ? A[L++] : 0), S += (!(R & 1) ? A[R--] : 0); } return S; }
    void UPDATE (int U, int V) { for (A[U + N] += V, U = ((U + N) / 2); U >= 1; U /= 2) A[U] = A[2 * U] + A[2 * U + 1]; }
};
 
int main() {
	ios::sync_with_stdio(0); 
	cin.tie(nullptr);
 
	int N, Q; cin >> N >> Q; vector<long long> A(N); for (long long &i : A) cin >> i;
	vector<long long> B = A; for (int i = 1; i < N; i++) B[i] = A[i] - A[i - 1]; SegTree C(N, B);
	
	while (Q--) {
		int T; cin >> T; if (T == 1) { int K1, K2, V; cin >> K1 >> K2 >> V; C.UPDATE(K1 - 1, V), C.UPDATE(K2, -V); }
		else if (T == 2) { int L = 0, R; cin >> R; cout << C.SUM(L, R - 1) << "\n"; }
	}
 
	return 0;
}