#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	int s = 1, l = n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		if (!((i + 1) % k)) a[i] = s, s++;
		else a[i] = l, l--;
	}

	for (int i = 0; i < n; i++) {
		if (i == (n - 1)) cout << a[i] << "\n";
		else cout << a[i] << " ";
	}
	
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	for (int i = 1; i <= t; i++) solve();

	return 0;
}