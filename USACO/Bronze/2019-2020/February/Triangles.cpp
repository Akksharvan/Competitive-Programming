#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N; vector<pair<int, int>> A(N);
	int res = INT_MIN; for (pair<int, int> &a : A) cin >> a.first >> a.second;

	for (pair<int, int> &a : A) {
		for (pair<int, int> &b : A) {
			for (pair<int, int> &c : A) {
				if (a.first == b.first && a.second == c.second) {
					res = max(res, abs(a.second - b.second) * abs(a.first - c.first));
				}
			}
		}
	}

	cout << res << "\n";
	return 0;
}