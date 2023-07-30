#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<pair<int, int>> A(N);

	for (pair<int, int> &i : A) {
		cin >> i.first;
		cin >> i.second;
	}

	int R = 0;
	for (pair<int, int> &i : A) {
		if (i.first > i.second) R++;
	}

	cout << R << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}