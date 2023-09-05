#include <bits/stdc++.h>
using namespace std;

void setIO () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

void setIO (string s) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void dfs (int x, vector<bool> &v, vector<int> &t, vector<int> &adj) {
	if (v[x]) return;
	v[x] = 1; t[x]++;
	dfs(adj[x], v, t, adj);
}

int main () {
	setIO("factory");

	int N;
	cin >> N;

	vector<int> t(N + 1), adj(N + 1);
	for (int i = 0; i < N; i++) { int a, b; cin >> a >> b; adj[a] = b; }

	for (int i = 1; i <= N; i++) { vector<bool> v(N + 1); dfs(i, v, t, adj); }
	for (int i = 1; i <= N; i++) { if (t[i] == N) { cout << i << "\n"; return 0; } }

	cout << -1 << "\n";
	return 0;
}