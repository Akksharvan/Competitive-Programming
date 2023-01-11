#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> G(N);
	for (int &g : G) cin >> g;

	int sret = G[N - 1] + G[N - 2];
	int mret = min(G[N - 1], G[N - 2]);

	float ans = (float) (sret - mret);
	vector<int> res = {N - 2};

	for (int i = N - 3; i > 0; i--) {
		sret += G[i];
		mret = min(mret, G[i]);

		float a = (float) (sret - mret) / (float) (N - i - 1);
		if (a > ans) ans = a, res.clear(), res.push_back(i);
		else if (a == ans) res.push_back(i);
	}

	sort(begin(res), end(res));
	for (int &ans : res) cout << ans << "\n";
	
	return 0;
}