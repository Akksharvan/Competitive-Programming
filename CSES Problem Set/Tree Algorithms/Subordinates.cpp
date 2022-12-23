#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

vector<vector<int>> children(2e5);
vector<int> descendants_size(2e5);

void dfs(int node) {
	descendants_size[node] = 1;

	for (int child : children[node]) {
		dfs(child);
		descendants_size[node] += descendants_size[child];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		p--;

		children[p].push_back(i);
	}

	dfs(0);

	for (int i = 0; i < n; i++) {
		cout << descendants_size[i] - 1 << spc;
	}

	cout << nl;

	return 0;
}