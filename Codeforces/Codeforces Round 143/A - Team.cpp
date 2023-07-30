#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, res = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		bool a, b, c; cin >> a >> b >> c;
		if (a + b + c >= 2) res++;
	}

	cout << res << "\n";
	return 0;
}