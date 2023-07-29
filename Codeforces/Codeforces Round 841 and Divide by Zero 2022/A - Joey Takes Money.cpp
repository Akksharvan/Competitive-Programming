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

		long long int ret = 1;
		for (int &x : a) ret *= (long long int) x;

		cout << ((ret + (n - 1)) * 2022) << "\n";
	}

	return 0;
}