#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

set<int> hb;
int N, K, R = 1e9;

bool explsn (int p) {
	int ltn = -1;

	for (int i = 0; i < K; i++) {
		ltn = *hb.upper_bound(ltn);
		ltn += (2 * p);

		if (hb.upper_bound(ltn) == hb.end()) {
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int hl;
		cin >> hl;
		hb.insert(hl);
	}

	int l = 0, r = 1e9;
	while (l < r) {
		int m = l + (r - l) / 2;
		if (explsn(m)) {
			R = m;
			r = m;
		}
		else {
			l = m + 1;
		}
	}

	cout << R << nl;
	return 0;
}