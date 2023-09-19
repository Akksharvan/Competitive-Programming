#include <bits/stdc++.h>
using namespace std;

bool good (vector<pair<int, int>> &cs, int x1, int y1, int x2, int y2) {
	if (x1 >= x2 || y1 >= y2) return 0;

	int oc = 0;
	for (const pair<int, int> &c : cs) if (c.first < x1 || c.first > x2 || c.second < y1 || c.second > y2) oc++;

	return ((oc <= 3) ? 1 : 0);
}

int main() {
	freopen("reduce.in", "r", stdin);
	freopen("reduce.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> cows(N);
	for (pair<int, int> &cow : cows) cin >> cow.first >> cow.second;

	vector<vector<pair<int, int>>> cdns(4);

	sort(cows.begin(), cows.end());
	for (int i = 0; i < 4; i++) cdns[0].push_back(cows[i]);
	for (int i = N - 1; i >= N - 4; i--) cdns[1].push_back(cows[i]);

	sort(cows.begin(), cows.end(), [](const pair<int, int>& x, const pair<int, int> &y) {return x.second < y.second;});
	for (int i = 0; i < 4; i++) cdns[2].push_back(cows[i]);
	for (int i = N - 1; i >= N - 4; i--) cdns[3].push_back(cows[i]);

	int ret = INT_MAX;

	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			for (int k = 0; k <= 3; k++) {
				for (int l = 0; l <= 3; l++) {
					int x1 = min(min(cdns[0][i].first, cdns[1][j].first), min(cdns[2][k].first, cdns[3][l].first));
					int x2 = max(max(cdns[0][i].first, cdns[1][j].first), max(cdns[2][k].first, cdns[3][l].first));

					int y1 = min(min(cdns[0][i].second, cdns[1][j].second), min(cdns[2][k].second, cdns[3][l].second));
					int y2 = max(max(cdns[0][i].second, cdns[1][j].second), max(cdns[2][k].second, cdns[3][l].second));

					if (good(cows, x1, y1, x2, y2)) ret = min(ret, (x2 - x1) * (y2 - y1));
				}
			}
		}
	}

	cout << ret << "\n";
	return 0;
}