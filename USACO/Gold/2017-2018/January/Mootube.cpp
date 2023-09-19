#include <bits/stdc++.h>
using namespace std;

vector<array<int, 3>> E;
vector<int> L, S;

int find (int x) { while (x != L[x]) { x = L[x]; } return x; }
bool same (int a, int b) { return find(a) == find(b); }

void unite (int a, int b) {
	a = find(a); b = find(b);
	if (S[a] < S[b]) swap(a,b);
	S[a] += S[b]; L[b] = a;
}

int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

	int N, Q;
	cin >> N >> Q;

	E.resize(N - 1);
	L.resize(N + 1);
	S.resize(N + 1);

	for (array<int, 3> &e : E) cin >> e[1] >> e[2] >> e[0];
	for (int i = 0; i <= N; i++) L[i] = i;
	for (int i = 0; i <= N; i++) S[i] = 1;

	vector<array<int, 3>> R(Q);
	for (int q = 0; q < Q; q++) {
		cin >> R[q][0] >> R[q][1];
		R[q][2] = q;
	}

	sort(rbegin(E), rend(E));
	sort(rbegin(R), rend(R));

	vector<int> A(Q); int i = 0;
	for (array<int, 3> &r : R) {
		while (i < N && E[i][0] >= r[0]) { unite(E[i][1], E[i][2]); i++; }
		A[r[2]] = S[find(r[1])];
	}

	for (int &a : A) cout << (a - 1) << "\n";
	return 0;
}