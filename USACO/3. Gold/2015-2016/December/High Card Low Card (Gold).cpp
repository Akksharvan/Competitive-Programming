#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);

	int N; cin >> N; int res = 0;
	vector<int> B, E(N); vector<bool> C(2 * N + 1);

	for (int &e : E) cin >> e, C[e] = 1;
	for (int i = 1; i <= 2 * N; i++) if (!C[i]) B.push_back(i);

	sort(begin(B), end(B));
	reverse(begin(B), end(B));

	set<int> E1, E2;
	for (int i = 0; i < N / 2; i++) E1.insert(E[i]);
	for (int i = N / 2; i < N; i++) E2.insert(E[i]);

	for (int i = 0; i < N / 2; i++) {
		if (B[i] > *begin(E1)) { E1.erase(prev(E1.lower_bound(B[i]))); res++; }
		else E1.erase(prev(end(E1)));
	}

	for (int i = N / 2; i < N; i++) {
		if (B[i] < *prev(end(E2))) { E2.erase(E2.lower_bound(B[i])); res++; }
		else E2.erase(begin(E2));
	}

	cout << res << "\n";
	return 0;
}