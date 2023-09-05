#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, R;
	cin >> N >> M >> R;

	vector<int> C(N);
	for (int &c : C) cin >> c;

	vector<pair<int, int>> S(M);
	for (pair<int, int> &s : S) cin >> s.second >> s.first;

	vector<int> F(R);
	for (int &f : F) cin >> f;

	sort(begin(C), end(C));
	sort(rbegin(S), rend(S));
	sort(rbegin(F), rend(F));

	vector<long long int> PC(N + 1);
	vector<long long int> SC(N + 1);

	int r = 0;
	for (int i = 1; i <= N; i++) PC[i] = PC[i - 1] + (r < R ? F[r] : 0), r++;

	int m = 0;
	for (int i = N - 1; i >= 0; i--) {
		SC[i] = SC[i + 1];

		while (m < M && C[i]) {
			int g = min(S[m].second, C[i]);
			
			SC[i] += (g * S[m].first);
			S[m].second -= g; C[i] -= g;

			if (!S[m].second) m++;
		}
	}

	long long int ans = INT_MIN;
	for (int i = 0; i < N; i++) {
		long long int res = PC[i] + SC[i];
		if (res > ans) ans = res;
	}

	cout << ans << "\n";
	return 0;
}