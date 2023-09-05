#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

bool impossible = false;

int K = 0;
array<bool, (int) 2e5> vegetation;
array<bool, (int) 2e5> visited;

vector<vector<int>> adjacency_list_S(2e5);
vector<vector<int>> adjacency_list_D(2e5);

void dfs (int node, bool marker) {
	visited[node] = true;
	vegetation[node] = marker;

	for (const int& leaf : adjacency_list_S[node]) {
		if (visited[leaf]) {
			if (vegetation[node] != vegetation[leaf]) {
				impossible = true;
				break;
			}
		}
		else {
			dfs(leaf, marker);
		}
	}

	for (const int& leaf : adjacency_list_D[node]) {
		if (visited[leaf]) {
			if (vegetation[node] == vegetation[leaf]) {
				impossible = true;
				break;
			}
		}
		else {
			dfs(leaf, !marker);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		char c;
		int a, b;

		cin >> c >> a >> b;
		a--;
		b--;

		if (c == 'S') {
			adjacency_list_S[a].push_back(b);
			adjacency_list_S[b].push_back(a);
		}
		else {
			adjacency_list_D[a].push_back(b);
			adjacency_list_D[b].push_back(a);
		}
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i] && !impossible) {
			K++;
			dfs(i, true);
		}
	}

	if (impossible) {
		cout << 0 << nl;
	}
	else {
		cout << 1;
		while (K--) {
			cout << 0;
		}
		cout << nl;
	}

	return 0;
}