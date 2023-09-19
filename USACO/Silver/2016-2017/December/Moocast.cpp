#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int square (int number) {
	return number * number;
}

int dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int count) {
	visited[node] = true;
	count++;

	for (const int& n : graph[node]) {
		if (!visited[n]) {
			count = dfs(n, graph, visited, count);
		}
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	int N;
	cin >> N;

	vector<array<int, 3>> cows(N);
	for (array<int, 3>& cow : cows) {
		cin >> cow[0] >> cow[1] >> cow[2];
	}

	vector<vector<int>> cows_adjacency_list(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (square(cows[i][2]) >= square(cows[i][0] - cows[j][0]) + square(cows[i][1] - cows[j][1])) {
				cows_adjacency_list[i].push_back(j);
			}
		}
	}

	int max_cows_reached = 0;
	for (int i = 0; i < N; i++) {
		vector<bool> v(N);
		int cows_reached = 0;
		max_cows_reached = max(max_cows_reached, dfs(i, cows_adjacency_list, v, cows_reached));
	}

	cout << max_cows_reached << nl;
	return 0;
}