#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;

	vector<int> hunger_values(N);
	long long int res = 0;

	for (int i = 0; i < N; i++) cin >> hunger_values[i];
	if (N == 1) { cout << "0" << "\n"; return; }

	for (int c = 0; c < 2; c++) {
		for (int i = 1; i < N - 1; i++) {
			int difference = hunger_values[i] - hunger_values[i - 1];
			if (difference > 0) { res += (2 * difference); hunger_values[i + 1] -= difference; hunger_values[i] = hunger_values[i - 1]; }
		}
		
		if (hunger_values[N - 1] > hunger_values[N - 2]) { cout << "-1" << "\n"; return; }
		reverse(hunger_values.begin(), hunger_values.end());
	}

	if (hunger_values[0] < 0) cout << "-1" << "\n";
	else cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}