#include <bits/stdc++.h>
using namespace std;

struct Friend { long long int a, b, c; };

bool foo(int X, int t_c, int t_m, vector<Friend> &F) {
	int C = t_c, M = t_m;
	M -= min(t_m - 1, X); X -= min(t_m - 1, X);
	C -= min(t_c - 1, X); X -= min(t_c - 1, X);

	int S = min(C - 1, t_m - M);
	int ret = 0;

	for (Friend &f : F) {
		if (f.a * C + f.b * M <= f.c) continue;
		if (f.b >= f.a) return 0;
		if (((f.a * C + f.b * M) - f.c) % (f.a - f.b)) ret = max(ret, (int) (((f.a * C + f.b * M) - f.c) / (f.a - f.b) + 1));
		else ret = max(ret, (int) (((f.a * C + f.b * M) - f.c) / (f.a - f.b)));
		if (ret > S) return 0;
	}

	C -= ret; M += ret;
	for (Friend &f : F) if (f.a * C + f.b * M > f.c) return 0;
	return 1;
}

void solve() {
	int N, t_c, t_m; cin >> N >> t_c >> t_m;
	vector<Friend> F(N); for (Friend &f : F) cin >> f.a >> f.b >> f.c;

	int L = 0, H = (int) 2e9 - 1;
	while (L < H) {
		int X = L + (H - L) / 2;
		if (foo(X, t_c, t_m, F)) H = X;
		else L = X + 1;
	}

	cout << L << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}