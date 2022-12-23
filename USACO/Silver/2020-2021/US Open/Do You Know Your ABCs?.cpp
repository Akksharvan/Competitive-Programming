#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

set<multiset<int>> t;

bool cs (int a, int b, int c, vector<int>& x) {
	for (int& xi : x) {
		if (!(xi == 0 || xi == a || xi == b || xi == c || xi == a + b || xi == a + c || xi == b + c || xi == a + b + c)) {
			return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		t.clear();

		int N;
		cin >> N;

		vector<int> x(N);
		for (int i = 0; i < N; i++) {
			cin >> x[i];
		}

		x.emplace(x.end(), 0);
		sort(x.begin(), x.end());

		set<int> d;
		for (int xi : x) {
			d.insert(xi);
			
			for (int xj : x) {
				if (xi < xj) {
					d.insert(xj - xi);
				}
			}
		}

		for (int a : d) {
			for (int b : d) {
				for (int c : d) {
					if (cs(a, b, c, x)) {
						multiset<int> tc;
						tc.insert(a);
						tc.insert(b);
						tc.insert(c);
						t.insert(tc);
					}
				}
			}
		}

		cout << sz(t) << nl;
	}

	return 0;
}