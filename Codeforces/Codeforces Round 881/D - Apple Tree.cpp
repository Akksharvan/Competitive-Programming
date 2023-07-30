#include <bits/stdc++.h>
using namespace std;

void foo (int U, int P, vector<vector<int>> &A, vector<int> &B) {
    if (size(A[U]) == 1 && A[U][0] == P) { B[U] = 1; return; }

    for (int V : A[U]) {
        if (V == P) continue;
        foo(V, U, A, B); B[U] += B[V];
    }
}

void solve() {
    int N; cin >> N;
    vector<vector<int>> A(N + 1);
    
    for (int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        A[a].push_back(b); A[b].push_back(a);
    }

    vector<int> B(N + 1);
    foo(1, 0, A, B);

    int Q; cin >> Q;
    while (Q--) {
        int x, y; cin >> x >> y;
        cout << ((long long) B[x] * (long long) B[y]) << "\n";
    }

    for (int i = 1; i <= N; i++) {
        cerr << B[i] << " ";
    }

    cerr << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
	
	return 0;
}