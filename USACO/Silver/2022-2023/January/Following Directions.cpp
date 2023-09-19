#include <bits/stdc++.h>
using namespace std;

int N, Q; int ret = 0;
array<array<int, 1501>, 1501> G;
array<array<int, 1502>, 1502> C;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++) { for (int j = 1; j <= N; j++) { char d; cin >> d; G[i][j] = ((d == 'R') ? 1 : 0); } cin >> C[i][N + 1]; }
	for (int j = 1; j <= N; j++) cin >> C[N + 1][j];

	queue<pair<int, int>> V;
	for (int i = 1; i <= N; i++) {
		if (G[i][N]) { C[i][N] = C[i][N + 1]; ret += C[i][N]; V.push({i, N}); }
		if (!G[N][i]) { C[N][i] = C[N + 1][i]; ret += C[N][i]; V.push({N, i}); }
	}

	while (!V.empty()) {
		int x = V.front().first, y = V.front().second; V.pop();
		if (y - 1 >= 1 && G[x][y - 1]) { C[x][y - 1] = C[x][y]; ret += C[x][y]; V.push({x, y - 1}); }
		if (x - 1 >= 1 && !G[x - 1][y]) { C[x - 1][y] = C[x][y]; ret += C[x][y]; V.push({x - 1, y}); }
	}

	cout << ret << "\n";
	cin >> Q;

	while (Q--) {
		int x, y;
		cin >> x >> y;

		int rex = C[x][y], ct = 0;
		G[x][y] = !G[x][y];

		if (G[x][y]) { ret -= C[x][y]; C[x][y] = C[x][y + 1]; ret += C[x][y]; V.push({x, y}); }
		if (!G[x][y]) { ret -= C[x][y]; C[x][y] = C[x + 1][y]; ret += C[x][y]; V.push({x, y}); }

		while (!V.empty()) {
			x = V.front().first, y = V.front().second; V.pop();
			if (y - 1 >= 1 && G[x][y - 1]) { ret -= C[x][y - 1]; C[x][y - 1] = C[x][y]; ret += C[x][y]; V.push({x, y - 1}); }
			if (x - 1 >= 1 && !G[x - 1][y]) { ret -= C[x - 1][y]; C[x - 1][y] = C[x][y]; ret += C[x][y]; V.push({x - 1, y}); }
		}

		cout << ret << "\n";
	}

	return 0;
}