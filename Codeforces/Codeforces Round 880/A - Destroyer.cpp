#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for (int &i : A) cin >> i;
	
	map<int, int> B;
	for (int &i : A) B[i]++;

	for (int i = 1; i < 100; i++) { if (B[i] > B[i - 1]) { cout << "NO" << "\n"; return; } }
	cout << "YES" << "\n"; return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}