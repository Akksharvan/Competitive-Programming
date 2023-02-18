#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; string s;
	cin >> n >> s;

	vector<int> a(26);
	vector<int> b(26);

	int cur_a = 0;
	int cur_b = 0;

	a[s[0] - 97]++;
	cur_a++;

	for (int i = 1; i < (int) s.size(); i++) {
		if (!b[s[i] - 97]) cur_b++;
		b[s[i] - 97]++;
	}

	int res = cur_a + cur_b;
	for (int i = 1; i < (int) s.size() - 1; i++) {
		if (!a[s[i] - 97]) cur_a++;
		if (b[s[i] - 97] == 1) cur_b--;

		a[s[i] - 97]++; b[s[i] - 97]--;
		res = max(res, cur_a + cur_b);
	}

	cout << res << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}