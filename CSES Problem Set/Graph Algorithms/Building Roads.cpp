#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

void dfs (int node, vector<vector<int>>& graph, vector<bool>& visited) {
	visited[node] = true;
	for (int linked_city : graph[node]) {
		if (!visited[linked_city]) {
			dfs(linked_city, graph, visited);
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

	int c = 0;
	vector<int> cc;

	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			c++;
			cc.push_back(i);
			dfs(i, g, v);
		}
	}

	cout << (c - 1) << nl;
	for (int i = 1; i < sz(cc); i++) {
		cout << (cc[0] + 1) << spc << (cc[i] + 1) << nl;
	}

	return 0;
}