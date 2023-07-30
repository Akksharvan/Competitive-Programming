#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x; cin >> n >> x;
	if (((n * (n + 1) / 2) - x) % 2) { cout << "IMPOSSIBLE" << "\n"; return 0; }

	int ret = (((n * (n + 1) / 2) - x) / 2); vector<bool> a(n);
	while (ret) if (ret >= n) { ret -= n--; a[n] = 1; } else { n--; }

	cout << 0;
	for (int i = 0; i < a.size(); i++) cout << (a[i] ? '-' : '+') << to_string(i + 1);

	cout << "\n";
	return 0;
}