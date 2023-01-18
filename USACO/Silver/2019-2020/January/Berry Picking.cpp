#include <bits/stdc++.h>
using namespace std;

int MOD;
bool foo (const int &x, const int &y) { return (x % MOD) > (y % MOD); }

int main() {
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> B(N);
	for (int &b : B) cin >> b;

	int M = INT_MIN; const int MAX = (*(max_element(begin(B), end(B))));
	for (MOD = 1; MOD <= MAX; MOD++) {
		int F = 0; for (int &b : B) F += b / MOD;

		if (F < K / 2) break;
		if (F >= K) { M = max(M, MOD * (K / 2)); continue; };
		
		int R = MOD * (F - (K / 2));
		sort(begin(B), end(B), foo);

		for (int i = 0; i < K - F; i++) R += B[i] % MOD;
		M = max(M, R);
	}

	cout << M << "\n";
	return 0;
}