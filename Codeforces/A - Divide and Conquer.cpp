#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

array<int, (int) 1e6 + 1> parity_ops;

int parity_change (int x) {
	int parity = (x % 2);
	int ops = 0;

	while (x % 2 == parity) {
		x /= 2;
		ops++;
	}

	return ops;
}

bool cmp (const int &x, const int &y) {
	return parity_ops[x] < parity_ops[y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= (int) 1e6; i++) {
		parity_ops[i] = parity_change(i);
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
		}

		vector<int> e;
		vector<int> o;

		for (int &x : a) {
			if (x % 2 == 0) {
				e.push_back(x);
			}
			else {
				o.push_back(x);
			}
		}

		if (sz(o) % 2 == 0) {
			cout << 0 << nl;
		}
		else {
			sort(e.begin(), e.end(), cmp);
			sort(o.begin(), o.end(), cmp);

			if (sz(e) != 0) {
				cout << min(parity_ops[o[0]], parity_ops[e[0]]) << nl;
			}
			else {
				cout << parity_ops[o[0]] << nl;
			}
		}
	}

	return 0;
}