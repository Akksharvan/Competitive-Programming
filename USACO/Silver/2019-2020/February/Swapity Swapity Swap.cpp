#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

array<int, (int) 1e5> cp;
array<vector<int>, (int) 1e5> ccs;
array<bool, (int) 1e5> v;

int ccn = -1;

void dfs (int node, int component) {
	v[node] = true;
	ccs[component].push_back(node);

	if (!v[cp[node]]) {
		dfs(cp[node], component);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cp[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		a--;
		b--;

		reverse(cp.begin() + a, cp.begin() + b + 1);
	}

	for (int i = 0; i < N; i++) {
		if (!v[i]) {
			dfs(i, ++ccn);
		}
	}

	for (const vector<int>& cc : ccs) {
		for (int j = 0; j < sz(cc); j++) {
			cp[cc[j]] = cc[(j + K) % sz(cc)] + 1;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << cp[i] << nl;
	}

	return 0;
}