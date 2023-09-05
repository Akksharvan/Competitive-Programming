#include <bits/stdc++.h>
using namespace std;

bool foo (vector<int> &x, vector<int> &y) {
	int ret1 = 0, ret2 = 0;

	for (const int &r1 : x) {
		for (const int &r2 : y) {
			if (r1 > r2) ret1++;
			else if (r1 < r2) ret2++;
		}
	}

	if (ret1 > ret2) return 1;
	else return 0;
}

void solve() {
	vector<vector<int>> D;

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			for (int k = 1; k <= 10; k++) {
				for (int l = 1; l <= 10; l++) {
					D.push_back({i, j, k, l});
				}
			}
		}
	}

	vector<int> A(4), B(4);
	cin >> A[0] >> A[1] >> A[2] >> A[3] >> B[0] >> B[1] >> B[2] >> B[3];

	if (foo (A, B) || foo (B, A)) {
		if (foo (B, A)) { vector<int> S = B; B = A; A = S; }
		for (vector<int> &C : D) { if (foo (B, C) && foo (C, A)) { cout << "yes" << "\n"; return; } }
	}
	
	cout << "no" << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}