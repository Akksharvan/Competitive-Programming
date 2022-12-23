#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

array<int, (int) 1e5> p;
long long int N, K, L;

bool f (int h) {
	if (h == 0) {
		return true;
	}

	long long int nc = 0;
	for (int i = 0; i < h; i++) {
		nc += max(0, h - p[i]);
	}

	if (nc <= K * L && (p[h - 1] >= h || h - p[h - 1] <= K)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K >> L;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}

	sort(p.begin(), p.begin() + N);
	reverse(p.begin(), p.begin() + N);

	int l = 0, h = N, k = N / 2;
	while (l < h) {
		int m = (l + h + 1) / 2;

		if (f(m)) {
			k = m;
			l = m;
		}
		else {
			h = m - 1;
		}
	}

	cout << k << nl;
	return 0;
}