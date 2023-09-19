#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int max_width = 1e9;

array<int, (int) 1e5> visited;
array<int, (int) 1e5> cows;
array<int, (int) 1e5> sorted_cows;
array<int, (int) 1e5> wormhole_widths;

void dfs(int node, vector<vector<pair<int, int>>>& adjacency_list, int weight, int marker) {
	visited[node] = marker;

	for (pair<int, int>& leaflets : adjacency_list[node]) {
		if (!visited[leaflets.first] && leaflets.second >= weight) {
			dfs(leaflets.first, adjacency_list, weight, marker);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int cow;
		cin >> cow;
		cow--;
		
		cows[i] = cow;
		sorted_cows[i] = cow;
	}

	sort(begin(sorted_cows), begin(sorted_cows) + N);

	if (cows == sorted_cows) {
		cout << -1 << nl;
		return 0;
	}

	vector<vector<pair<int, int>>> wormholes_adjacency_list(M);
	for (int i = 0; i < M; i++) {
		int a, b, w;
		cin >> a >> b >> w;

		a--;
		b--;

		wormhole_widths[i] = w;
		wormholes_adjacency_list[a].push_back({b, w});
		wormholes_adjacency_list[b].push_back({a, w});
	}

	sort(begin(wormhole_widths), begin(wormhole_widths) + M);

	int left = 0, right = M - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		bool possible = true;
		int marker = 1;

		fill(begin(visited), begin(visited) + N, 0);
		for (int node = 0; node < N; node++) {
			if (!visited[node]) {
				dfs(node, wormholes_adjacency_list, wormhole_widths[mid], marker++);
			}
		}

		for (int i = 0; i < N; i++) {
			if (visited[i] != visited[cows[i]]) {
				possible = false;
				break;
			}
		}

		if (possible) {
			max_width = wormhole_widths[mid];
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << max_width << nl;
	return 0;
}