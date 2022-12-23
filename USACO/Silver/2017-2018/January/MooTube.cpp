#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

vector<vector<pair<int, int>>> children(5e3);
vector<bool> visited(5e3);
int relevant_videos = 0;

void dfs (int node, int minimum_relevance, int relevance) {
	visited[node] = true;

	for (pair<int, int>& child : children[node]) {
		if (!visited[child.first]) {
			int new_relevance = min(relevance, child.second);
			if (new_relevance >= minimum_relevance) {
				relevant_videos++;
			}

			dfs(child.first, minimum_relevance, new_relevance);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

	int N, Q;
	cin >> N >> Q;

	for (int i = 0; i < N - 1; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		p--, q--;

		children[p].push_back({q, r});
		children[q].push_back({p, r});
	}

	for (int i = 0; i < Q; i++) {
		int k, v;
		cin >> k >> v;
		v--;

		fill(begin(visited), begin(visited) + N, 0);
		relevant_videos = 0;

		dfs(v, k, 1e9);
		cout << relevant_videos << nl;
	}

	return 0;
}