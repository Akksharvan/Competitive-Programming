#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> cows(N);
	for (pair<int, int> &cow : cows) cin >> cow.second >> cow.first;

	int ret = INT_MIN;
	sort(cows.begin(), cows.end());

	int l = 0, r = N - 1;
	while (l <= r) {
		ret = max(ret, cows[l].first + cows[r].first);

		int d = min(cows[l].second, cows[r].second);
		if (l == r) d /= 2;
		
		cows[l].second -= d;
		cows[r].second -= d;

		if (!cows[l].second) l++;
		if (!cows[r].second) r--;
	}
	
	cout << ret << "\n";
	return 0;
}