#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

void dfs (int node, bool group, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& groups) {
	visited[node] = true;
	groups[node] = group;
	for (int next_node : graph[node]) {
		if (!visited[next_node]) {
			dfs(next_node, !group, graph, visited, groups);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	vector<bool> v(n);

	while (m--) {
		int a, b;
		cin >> a >> b;

		a--;
		b--;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<bool> gp(n);

	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			dfs(i, 0, g, v, gp);
		}
	}

	bool p = true;

	for (int i = 0; i < n; i++) {
		for (const int& n : g[i]) {
			if (gp[i] == gp[n]) {
				p = false;
				break;
			}
		}

		if (!p) {
			break;
		}
	}

	if (p) {
		for (const bool& b : gp) {
			cout << (b + 1) << spc;
		}
	}
	else {
		cout << "IMPOSSIBLE";
	}

	cout << nl;

	return 0;
}