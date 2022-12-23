#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

void dfs (int node, vector<vector<int>>& graph, vector<bool>& visited, array<int, 4>& dimensions, vector<pair<int, int>>& cows) {
	visited[node] = true;
	dimensions[0] = min(dimensions[0], cows[node].first), dimensions[1] = max(dimensions[1], cows[node].first), dimensions[2] = min(dimensions[2], cows[node].second), dimensions[3] = max(dimensions[3], cows[node].second);

	for (const int& n : graph[node]) {
		if (!visited[n]) {
			dfs(n, graph, visited, dimensions, cows);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> cows(N);
	for (pair<int, int>& cow : cows) {
		cin >> cow.first >> cow.second;
	}

	vector<vector<int>> cows_adjacency_list(N);
	vector<bool> v(N);
	while (M--) {
		int a, b;
		cin >> a >> b;

		a--;
		b--;

		cows_adjacency_list[a].push_back(b);
		cows_adjacency_list[b].push_back(a);
	}

	int minimum_perimeter = 4 * (1e8);

	for (int i = 0; i < N; i++) {
		if (!v[i]) {
			array<int, 4> ds;
			ds[0] = 1e8, ds[1] = 0, ds[2] = 1e8, ds[3] = 0;
			dfs(i, cows_adjacency_list, v, ds, cows);

			int perimeter = (2 * (ds[1] - ds[0])) + (2 * (ds[3] - ds[2]));
			minimum_perimeter = min(minimum_perimeter, perimeter);
		}
	}

	cout << minimum_perimeter << nl;
	return 0;
}