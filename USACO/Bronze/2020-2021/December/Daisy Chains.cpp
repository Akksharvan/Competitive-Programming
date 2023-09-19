#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	vector<int> P(N); for (int &p : P) cin >> p;

	int res = 0;
	for (int i = 0; i < N; i++) {
		int ret = 0;

		for (int j = i; j < N; j++) {
			ret += P[j]; int n = j - i + 1; if (ret % n) continue;
			for (int k = i; k <= j; k++) {
				if (P[k] == ret / n) { res++; break; }
			}
		}
	}

	cout << res << "\n";
	return 0;
}