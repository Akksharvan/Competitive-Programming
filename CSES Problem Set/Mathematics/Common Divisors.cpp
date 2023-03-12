#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n; vector<int> a((int) 1e6 + 1);
	for (int i = 0; i < n; i++) { int x; cin >> x; a[x]++; }

	for (int i = (int) 1e6; i > 0; i--) {
		int ret = 0;
		for (int j = i; j <= (int) 1e6; j += i) ret += a[j];
		if (ret >= 2) { cout << i << "\n"; break; }
	}

	return 0;
}