#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, M; cin >> N >> M;
	vector<vector<int>> A(N + 1);

	while (M--) {
		int u, v; cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}

	map<int, int> B;
	for (int i = 1; i <= N; i++) {
		B[(int) size(A[i])]++;
	}

	int x, y;
	if ((int) size(B) == 2) {
		for (const pair<int, int> &b : B) {
			if (b.first == 1) continue;
			x = b.second - 1; y = b.first - 1; 
		}
	}
	else {
		for (const pair<int, int> &b : B) {
			if (b.first == 1) continue;
			if (b.second == 1) x = b.first;
			else y = b.first - 1;
		}
	}

	cout << x << " " << y << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}