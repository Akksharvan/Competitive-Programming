#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);

	int N, Q;
	cin >> N >> Q;

	vector<int> cows(N);
	for (int &cow : cows) cin >> cow;

	vector<vector<int>> cows_prefix(4, vector<int> (N + 1));
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= N; j++) {
			cows_prefix[i][j] = cows_prefix[i][j - 1] + (cows[j - 1] == i);
		}
	}

	while (Q--) {
		int a, b, H, G, J;
		cin >> a >> b;

		for (int i = 1; i <= 3; i++) {
			if (i == 1) {
				H = cows_prefix[i][b] - cows_prefix[i][a - 1];
			}
			else if (i == 2) {
				G = cows_prefix[i][b] - cows_prefix[i][a - 1];
			}
			else {
				J = cows_prefix[i][b] - cows_prefix[i][a - 1];
			}
		}

		cout << H << spc << G << spc << J << nl;
	}

	return 0;
}