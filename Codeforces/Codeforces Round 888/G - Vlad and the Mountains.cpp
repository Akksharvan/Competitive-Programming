#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> E; DSU (int N) { E = vector<int>(N, -1); }
	int G (int x) { return E[x] < 0 ? x : E[x] = G(E[x]); }
	
    bool S (int a, int b) { return G(a) == G(b); }
	int SZ (int x) { return -E[G(x)]; }

	bool U (int x, int y) {
		x = G(x), y = G(y);
		if (x == y) return 0;

		if (E[x] > E[y]) swap(x, y);
		E[x] += E[y]; E[y] = x; return 1;
	}
};

bool F (array<int, 3> &x, array<int, 3> &y) { return (x[2] < y[2]); }
bool G (array<int, 4> &x, array<int, 4> &y) { return (x[2] < y[2]); }

void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N + 1); for (int i = 1; i <= N; i++) cin >> A[i];

    vector<array<int, 3>> B(M);
    for (array<int, 3> &i : B) {
        cin >> i[0] >> i[1];
        i[2] = max(A[i[0]], A[i[1]]);
    }

    sort(begin(B), end(B), F);
    reverse(begin(B), end(B));

    int Q; cin >> Q;
    vector<array<int, 4>> C(Q);
    
    for (int i = 0; i < Q; i++) {
        cin >> C[i][0] >> C[i][1] >> C[i][2];
        C[i][2] += A[C[i][0]]; C[i][3] = i;
    }

    sort(begin(C), end(C), G);
    vector<string> R(Q); DSU D(N + 1);

    for (array<int, 4> &i : C) {
        while (!B.empty() && B[size(B) - 1][2] <= i[2]) {
            D.U(B[size(B) - 1][0], B[size(B)- 1][1]);
            B.pop_back();
        }

        if (D.S(i[0], i[1])) R[i[3]] = "YES";
        else R[i[3]] = "NO";
    }

    for (string &s : R) cout << s << "\n";
    cout << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) solve();

    return 0;
}