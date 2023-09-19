#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int K, M, N;
	cin >> K >> M >> N;

	vector<pair<int, int>> k(K);
	for (int i = 0; i < K; i++) {
		cin >> k[i].first >> k[i].second;
	}
	
	vector<int> m(M);
	for (int i = 0; i < M; i++) {
		cin >> m[i];
	}

	sort(k.begin(), k.end());
	sort(m.begin(), m.end());

	vector<long long int> t;
	t.push_back(0);
	t.push_back(0);

	int ki, kf;

	for (int i = 0; i < K; i++) {
		if (k[i].first < m[0]) {
			t[0] += k[i].second;
			ki = i;
		}
	}

	for (int i = K - 1; i >= 0; i--) {
		if (k[i].first > m[M - 1]) {
			t[1] += k[i].second;
			kf = i;
		}
	}

	for (int l = 0; l < M - 1; l++) {
		vector<pair<int, int>> ks;

		while (ki < kf) {
			if (k[ki].first < m[l]) {
				ki++;
			}
			else if (k[ki].first > m[l] && k[ki].first < m[l + 1]) {
				ks.push_back((k[ki]));
				ki++;
			}
			else {
				break;
			}
		}

		long long int s = 0, ms = 0, cs = 0;
		int w = (m[l + 1] - m[l]) / 2;

		for (int i = 0; i < sz(ks); i++) {
			s += ks[i].second;
		}

		int x = 0, y = 0;
		while (x < sz(ks)) {
			while (y < sz(ks)) {
				if (ks[y].first - ks[x].first >= w) {
					break;
				}
				else {
					cs += ks[y].second;
					y++;
				}
			}

			ms = max(ms, cs);
			x = y;
			cs = 0;
		}

		t.push_back(ms);
		t.push_back(s - ms);
	}

	sort(t.rbegin(), t.rend());
	long long int ty = 0;

	for (int i = 0; i < sz(t); i++) {
		ty += t[i];
		N--;

		if (N == 0) {
			break;
		}
	}

	cout << ty << nl;
	return 0;
}