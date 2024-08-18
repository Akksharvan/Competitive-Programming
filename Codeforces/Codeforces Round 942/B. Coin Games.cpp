#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; string S; cin >> N >> S;
	int U = count(begin(S), end(S), 'U');

	if (!(U & 1)) cout << "NO" << "\n";
	else cout << "YES" << "\n"; return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();
}