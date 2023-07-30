#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<int> a(n); for (int &x : a) cin >> x;

	int res = 0; for (int i = 0; i < n; i++) if (a[i] && a[i] >= a[k - 1]) res++;
	cout << res << "\n"; return 0;
}