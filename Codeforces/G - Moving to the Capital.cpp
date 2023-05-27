#include <bits/stdc++.h>
using namespace std;

vector<int> foo(vector<vector<int>> const &g) {
  vector<int> a(g.size(), -1); a[1] = 0;
  queue<int> pq; pq.push(1);

  while (!pq.empty()) {
    int u = pq.front(); pq.pop();
    for (int v : g[u]) { if (a[v] == -1) { a[v] = a[u] + 1; pq.push(v); } }
  }

  return a;
}

void dfs(int u, vector<vector<int>> const &g, vector<int> const &a, vector<int> &dp, vector<bool> &b) {
  b[u] = 1; dp[u] = a[u];

  for (int v : g[u]) {
    if (!b[v] && a[u] < a[v]) dfs(v, g, a, dp, b);

    if (a[u] < a[v]) dp[u] = min(dp[u], dp[v]);
    else dp[u] = min(dp[u], a[v]);
  }

  return;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; i++) { int u, v; cin >> u >> v; g[u].push_back(v); }
	
	vector<int> a = foo(g); vector<int> dp(n + 1);
	vector<bool> b(n + 1); dfs(1, g, a, dp, b);
	  
	for (int i = 1; i <= n; i++) cout << dp[i] << " ";	
	cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();
	
	return 0;
}