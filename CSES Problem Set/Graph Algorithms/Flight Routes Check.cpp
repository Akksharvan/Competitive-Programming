#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

void dfs (int node, vector<vector<int>>& combinations, vector<bool>& visited) {
	visited[node] = true;
	for (const int& combination : combinations[node]) {
		if (!visited[combination]) {
			dfs(combination, combinations, visited);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> fc_f(n), fc_b(n);

	while (m--) {
		int a, b;
		cin >> a >> b;

		a--;
		b--;

		fc_f[a].push_back(b);
		fc_b[b].push_back(a);
	}

	vector<vector<int>> ds(2);
	vector<bool> v_f(n), v_b(n);

	dfs(0, fc_f, v_f);
	dfs(0, fc_b, v_b);

	for (int i = 0; i < n; i++) {
		if (!v_f[i]) {
			cout << "NO" << nl;
			cout << 1 << spc << (i + 1) << nl;
			return 0;
		}
		else if (!v_b[i]) {
			cout << "NO" << nl;
			cout << (i + 1) << spc << 1 << nl;
			return 0;
		}
	}

	cout << "YES" << nl;
	return 0;
}