#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long Q; cin >> Q;
	unordered_map<long long, long long> A;

	while (Q--) {
		long long T; cin >> T;
		if (T == 0) { long long B, C; cin >> B >> C; A[B] = C; }
		else if (T == 1) { long long B; cin >> B; cout << A[B] << "\n"; }
	}

	return 0;
}