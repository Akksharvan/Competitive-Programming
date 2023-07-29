#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> w(2 * n);
	for (int &x : w) cin >> x;

	sort(w.begin(), w.end());
	long long int res = (long long int) INT_MAX;

	for (int i = 0; i < (2 * n - 1); i++) {
		for (int j = i + 1; j < (2 * n); j++) {
			long long int ret = 0;
			
			vector<int> b;
			for (int k = 0; k < (2 * n); k++) if (k != i && k != j) b.push_back(w[k]);

			for (int k = 0; k < (int) b.size() - 1; k += 2) ret += (b[k + 1] - b[k]);
			res = min(res, ret);
		}
	}

	cout << res << "\n";
	return 0;
}