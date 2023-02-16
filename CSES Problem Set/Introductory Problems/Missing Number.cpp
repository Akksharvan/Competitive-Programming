#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<bool> a(n);
	
	for (int i = 0; i < n; i++) { int x; cin >> x; a[--x] = 1; }
	for (int i = 0; i < n; i++) { if (!a[i]) { cout << i + 1 << "\n"; break; } }
	
	return 0;
}