#include <bits/stdc++.h>
using namespace std;
 
struct SegTree {
    int N; vector<long long> A;
    SegTree (int S, vector<long long> &B) { N = S, A.assign(2 * N, 0); for (int i = 0; i < (int) size(B); i++) UPDATE(i, B[i]); }
 
    long long SUM (int L, int R) { long long S = 0; for (L += N, R += N; L <= R; L /= 2, R /= 2) { S += ((L & 1) ? A[L++] : 0), S += (!(R & 1) ? A[R--] : 0); } return S; }
    void UPDATE (int U, int V) { for (A[U + N] = V, U = ((U + N) / 2); U >= 1; U /= 2) A[U] = A[2 * U] + A[2 * U + 1]; }
};
 
int main() {
	ios::sync_with_stdio(0); 
	cin.tie(nullptr);
 
	int N, Q; cin >> N >> Q;
	vector<int> A(N); for (int &i : A) cin >> i;
 
	vector<array<int, 3>> B(Q);
	for (array<int, 3> &i : B) {
		char T; cin >> T >> i[1] >> i[2];
		i[0] = (T == '!' ? 1 : 2);
	}
 
	int C = 0; set<int> D; for (int &i : A) D.insert(i);
	for (array<int, 3> &i : B) { D.insert(i[2]); if (i[0] == 2) D.insert(i[1]); else i[1]--; }
 
	unordered_map<int, int> E; for (const int &i : D) E[i] = C++; vector<long long> F(C);
	for (int &i : A) i = E[i]; for (int &i : A) F[i]++; for (array<int, 3> &i : B) { i[2] = E[i[2]]; if (i[0] == 2) i[1] = E[i[1]]; }
	
	SegTree G(C, F); for (array<int, 3> &i : B) {
		if (i[0] == 1) F[A[i[1]]]--, F[i[2]]++, G.UPDATE(A[i[1]], F[A[i[1]]]), G.UPDATE(i[2], F[i[2]]), A[i[1]] = i[2];
		else if (i[0] == 2) cout << G.SUM(i[1], i[2]) << "\n";
	}
	
	return 0;
}