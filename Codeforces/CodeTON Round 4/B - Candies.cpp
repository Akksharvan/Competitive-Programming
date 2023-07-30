#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	if (!(n % 2)) { cout << -1 << "\n"; return; }

	vector<int> res;
	while (n != 1) {
		if (((n + 1) / 2) % 2) { res.push_back(1); n = (n + 1) / 2; }
		else { res.push_back(2); n = (n - 1) / 2; }
	}

	reverse(begin(res), end(res)); cout << (int) res.size() << "\n";
	for (int &ret : res) cout << ret << " ";
	cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}