#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for (int &a : A) cin >> a;

	for (int &a : A) cout << ((N + 1) - a) << " ";
	cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}