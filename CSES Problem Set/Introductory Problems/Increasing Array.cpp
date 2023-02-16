#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<long long int> a(n); for (long long int &x : a) cin >> x;

	long long int res = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) { res += a[i - 1] - a[i]; a[i] = a[i - 1]; }
	}

	cout << res << "\n";
	return 0;
}