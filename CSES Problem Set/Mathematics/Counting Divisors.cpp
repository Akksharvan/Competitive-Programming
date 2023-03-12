#include <bits/stdc++.h>
using namespace std;

array<int, (int) 1e6 + 1> S;
void foo() { for (int i = 2; i <= (int) 1e6; i++) { if (!S[i]) { for (int j = i; j <= (int) 1e6; j += i) { S[j] = i; } } } return; }

void solve() {
	int x; cin >> x; map<int, int> a;
	while (x != 1) { a[S[x]]++; x /= S[x]; }

	long long int res = 1;
	for (const pair<int, int> &p : a) res *= p.second + 1;

	cout << res << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T; foo();
	for (int t = 1; t <= T; t++) solve();

	return 0;
}