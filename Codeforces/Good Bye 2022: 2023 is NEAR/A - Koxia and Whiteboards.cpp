#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	multiset<int> a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.insert(x);
	}

	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		a.erase(a.begin()); a.insert(x);
	}

	long long int ret = 0;
	for (int x : a) ret += (long long int) x;

	cout << ret << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	for (int i = 1; i <= t; i++) solve();

	return 0;
}