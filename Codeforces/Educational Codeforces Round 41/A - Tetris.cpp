#include <bits/stdc++.h>
using namespace std;

void solve() {
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<int> a(n); for (int i = 0; i < m; i++) { int x; cin >> x; a[x - 1]++; }

	sort(begin(a), end(a)); cout << a[0] << "\n";
	return 0;
}