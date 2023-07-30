#include <bits/stdc++.h>
using namespace std;

bool foo (int M, int N, vector<pair<int, int>> &A, vector<int> &B) {
    vector<int> C(N + 1); for (int i = 0; i <= M; i++) C[B[i]] = 1;
    for (int i = 1; i <= N; i++) C[i] += C[i - 1];

    for (pair<int, int> &i : A) {
        if (C[i.second] - C[i.first - 1] > ((i.second - i.first) + 1) / 2) {
            return 1;
        }
    }

    return 0;
}

void solve() {
    int N, M; cin >> N >> M; vector<pair<int, int>> A(M);
    for (pair<int, int> &i : A) cin >> i.first >> i.second;

    int Q; cin >> Q; int L = 0, H = Q;
    vector<int> B(Q); for (int &i : B) cin >> i;

	while (L < H) {
		int MD = L + (H - L) / 2;
		if (foo(MD, N, A, B)) H = MD;
		else L = MD + 1;
	}

	cout << (L == Q ? -1 : L + 1) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
	
	return 0;
}