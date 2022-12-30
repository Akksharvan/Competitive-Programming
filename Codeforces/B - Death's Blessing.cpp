#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long int t = 0;
		int n, max_b = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;

			t += a;
		}

		for (int i = 0; i < n; i++) {
			int b;
			cin >> b;

			t += b;
			max_b = max(max_b, b);
		}

		t -= max_b;
		cout << t << nl;
	}

	return 0;
}