#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int &x : a) cin >> x;

		map<int, vector<int>> b;
		for (int i = 0; i < n; i++) b[a[i]].push_back(i);

		int ret = 0;
		for (const pair<int, vector<int>> &x : b) if ((int) x.second.size() > 1) ret = max(ret, x.second[(int) x.second.size() - 2] + 1);

		cout << ret << "\n";
	}

	return 0;
}