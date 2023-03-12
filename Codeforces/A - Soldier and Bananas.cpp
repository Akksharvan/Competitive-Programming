#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, n, w; cin >> k >> n >> w;
	cout << max(0, ((k) * (w) * (w + 1) / 2) - n) << "\n";
	
	return 0;
}