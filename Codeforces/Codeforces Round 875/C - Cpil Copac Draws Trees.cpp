#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<vector<pair<int, int>>> A(N + 1);

	for (int i = 1; i < N; i++) {
		int u, v; cin >> u >> v;
		A[u].emplace_back(v, i);
		A[v].emplace_back(u, i);
	}

	vector<int> B(N + 1); B[1] = 1;
	stack<pair<int, int>> C; C.push({1, INT_MIN});

	while (!C.empty()) {
		pair<int, int> n = C.top(); C.pop();
		for (pair<int, int> &v : A[n.first]) {
			if (B[v.first]) continue;
			if (n.second < v.second) { B[v.first] = B[n.first]; C.push(v); }
			else { B[v.first] = B[n.first] + 1; C.push(v); }
		}
	}

	int R = INT_MIN; for (int &b : B) R = max(R, b);
	cout << R << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}