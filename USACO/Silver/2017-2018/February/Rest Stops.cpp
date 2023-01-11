#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long int L, N, f, b;
	cin >> L >> N >> f >> b;

	priority_queue<pair<int, int>> S;
	for (int i = 0; i < N; i++) { pair<int, int> s; cin >> s.second >> s.first; S.push(s); }

	long long int res = 0;
	long long int t = 0;

	while (!S.empty()) {
		if (S.top().second > t) res += S.top().first * ((f * (S.top().second - t)) - (b * (S.top().second - t))), t = S.top().second, S.pop();
		else S.pop();
	}

	cout << res << "\n";
	return 0;
}