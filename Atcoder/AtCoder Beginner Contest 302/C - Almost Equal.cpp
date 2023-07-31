#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<string> S(N); for (string &s : S) cin >> s;

	sort(begin(S), end(S));
	do {
		bool g = 1;
		for (int i = 0; i < N - 1; i++) {
			int ret = 0; for (int j = 0; j < M; j++) if (S[i][j] != S[i + 1][j]) ret++;
			if (ret > 1) { g = 0; break; }
		}

		if (g) { cout << "Yes" << "\n"; return 0; }
	} while (next_permutation(begin(S), end(S)));

	cout << "No" << "\n";
	return 0;
}