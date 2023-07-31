#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	string S; cin >> S;

	for (int i = 1; i < N; i++) {
		if (strcmp(S.substr(0, i).c_str(), S.substr(i, N - i).c_str()) < 0) {
			cout << "Yes" << "\n";
			return;
		}
	}

	cout << "No" << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}