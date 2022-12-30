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

	array<int, 10000> ps{};
	for (int x = 1; x <= 100; x++) {
		int xx = x * x;
		ps[xx] = x;
	}
	
	while (t--) {
		int m, s;
		cin >> m >> s;

		vector<int> sequence;
		for (int i = 0; i < m; i++) {
			int b;
			cin >> b;

			sequence.push_back(b);
		}

		sort(sequence.begin(), sequence.end());

		int n = sequence[m - 1];		
		int cs = 0;

		for (int i = 0; i < m; i++) {
			cs += sequence[i];
		}

		int es = (n * (n + 1)) / 2;
		s -= (es - cs);

		if (s < 0) {
			cout << "NO" << nl;
		}
		else {
			while (s > 0) {
				n++;
				s -= n;
			}

			if (s == 0) {
				cout << "YES" << nl;
			}
			else {
				cout << "NO" << nl;
			}
		}
	}

	return 0;
}