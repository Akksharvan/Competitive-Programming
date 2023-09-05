#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> G(3, vector<int> (N + 1));
	for (int i = 1; i <= N; i++) {
		char c; cin >> c;
		if (c == 'H') G[0][i]++;
		else if (c == 'P') G[1][i]++;
		else G[2][i]++;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= N; j++) G[i][j] += G[i][j - 1];
	}

	int ret = INT_MIN;
	for (int i = 1; i <= N; i++) {
		int pret = max(G[0][i], max(G[1][i], G[2][i]));
		int sret = max(G[0][N] - G[0][i], max(G[1][N] - G[1][i], G[2][N] - G[2][i]));
		ret = max(ret, pret + sret);
	}

	cout << ret << "\n";
	return 0;
}