#include <bits/stdc++.h>
using namespace std;

array<bool, 5000> visited;
array<bool, 5000> closed;

vector<vector<int>> adj(5000);

void dfs (int node) {
	visited[node] = 1;
	for (int &branch : adj[node]) if (!visited[branch] && !closed[branch]) dfs(branch);
}

int main() {
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	bool c = 1;
	for (int i = 1; i <= N; i++) if (!visited[i]) c = 0;

	cout << (c ? "YES" : "NO") << "\n";
	
	for (int q = 1; q < N; q++) {
		int closure;
		cin >> closure;

		closed[closure] = 1;
		fill(visited.begin(), visited.end(), 0);

		int cc = 0;
		for (int i = 1; i <= N; i++) if (!visited[i] && !closed[i]) dfs(i), cc++;

		cout << ((cc <= 1) ? "YES" : "NO") << "\n";
	}

	return 0;
}