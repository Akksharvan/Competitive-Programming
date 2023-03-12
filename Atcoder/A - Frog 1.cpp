#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	vector<int> H(N); for (int &h : H) cin >> h;

	vector<int> DP(N, INT_MAX); DP[0] = 0;
	for (int i = 0; i < N - 1; i++) {
		if (i < N - 2) {
			DP[i + 2] = min(DP[i + 2], DP[i] + abs(H[i] - H[i + 2]));
			DP[i + 1] = min(DP[i + 1], DP[i] + abs(H[i] - H[i + 1]));
		}
		else if (i < N - 1) DP[i + 1] = min(DP[i + 1], DP[i] + abs(H[i] - H[i + 1]));
	}

	cout << DP[N - 1] << "\n";
	return 0;
}