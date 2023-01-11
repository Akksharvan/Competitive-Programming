#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<array<int, 3>> L;
	for (int i = 0; i < N; i++) { int x, y; cin >> x >> y; L.push_back({x, y, i}); L.push_back({y, x, i}); }

	sort(begin(L), end(L));
	set<array<int, 3>> A;

	int t = 0, lt = 0;
	vector<int> T(N);

	for (array<int, 3> &l : L) {
		int ct = l[0];

		if ((int) A.size() == 1) T[(*begin(A))[2]] += (ct - lt);
		if (!A.empty()) t += (ct - lt);

		if (l[0] > l[1]) A.erase({l[1], l[0], l[2]});
		else A.insert(l);

		lt = ct;
	}

	int res = t - *(min_element(begin(T), end(T)));
	cout << res << "\n";
	
	return 0;
}