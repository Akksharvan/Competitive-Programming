#include <bits/stdc++.h>
using namespace std;

void solve() {
	int W, H, w, h, x1, y1, x2, y2;
	cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

	int res = INT_MAX;
	if (x2 - x1 + w <= W) { res = min(res, max(0, w - x1)); res = min(res, max(0, x2 - (W - w))); }
	if (y2 - y1 + h <= H) { res = min(res, max(0, h - y1)); res = min(res, max(0, y2 - (H - h))); }

	if (res == INT_MAX) cout << -1 << "\n";
	else cout << (double) (res) << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T; cout << fixed << setprecision(9);
	for (int t = 1; t <= T; t++) solve();

	return 0;
}