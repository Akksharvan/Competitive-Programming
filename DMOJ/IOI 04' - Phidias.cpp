#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int W, H, N;
	cin >> W >> H >> N;

	vector<pair<int, int>> A(N);
	for (pair<int, int> &a : A) cin >> a.first >> a.second;

	vector<vector<int>> DP(W + 1, vector<int> (H + 1));
	for (int i = 1; i <= W; i++) for (int j = 1; j <= H; j++) DP[i][j] = i * j;
	for (pair<int, int> &a : A) DP[a.first][a.second] = 0;

	for (int i = 1; i <= W; i++) {
		for (int j = 1; j <= H; j++) {
			for (int x = 1; x <= i; x++) DP[i][j] = min(DP[i][j], DP[x][j] + DP[i - x][j]);
			for (int y = 1; y <= j; y++) DP[i][j] = min(DP[i][j], DP[i][y] + DP[i][j - y]);
		}
	}
	
	cout << DP[W][H] << "\n";
	return 0;
}