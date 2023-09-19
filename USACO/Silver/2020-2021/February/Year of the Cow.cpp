#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	K--;

	vector<int> anc(N);
	for (int i = 0; i < N; i++) {
		cin >> anc[i];
	}
	sort(anc.begin(), anc.end());

	int C = anc[N - 1] / 12;
	vector<bool> cyc(C);

	for (int i = 0; i < N; i++) {
		int c = anc[i] / 12;
		cyc[c] = true;
	}

	int l = 0, r = 0, y = (C + 1) * 12;
	vector<int> g;

	while (l < C) {
		if (cyc[l]) {
			l++;
			r++;
		}
		else {
			break;
		}
	}

	while (l < C) {
		while (r < C) {
			r++;

			if (cyc[r]) {
				break;
			}
		}

		g.push_back(r - l);

		l = r;
		while (l < C) {
			if (cyc[l]) {
				l++;
				r++;
			}
			else {
				break;
			}
		}
	}

	sort(g.rbegin(), g.rend());
	for (int i = 0; i < sz(g); i++) {
		if (K > 0) {
			K--;
			y -= (g[i] * 12);
		}
		else {
			break;
		}
	}

	cout << y << nl;
	return 0;
}