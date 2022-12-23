#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

vector<vector<int>> children(2e5);
pair<int, int> farthest_node = {0, 0};

void dfs (int node, int previous_node, int distance) {
	if (distance > farthest_node.second) {
		farthest_node.first = node;
		farthest_node.second = distance;
	}

	for (int next_node : children[node]) {
		if (next_node != previous_node) {
			dfs(next_node, node, distance + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		
		a--;
		b--;

		children[a].push_back(b);
		children[b].push_back(a);
	}

	dfs(0, 0, 0);
	dfs(farthest_node.first, farthest_node.first, 0);

	cout << farthest_node.second << nl;
	return 0;
}