#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; string S;
	cin >> N >> S;

	vector<int> E(N);
	for (int &e : E) cin >> e;

	int G = S.find("G"), H = S.find("H");
	int res = 0;

	for (int i = 0; i < N; i++) {
		if (G != -1 && S[i] == 'G' && i > (E[G] - 1)) G = -1;
		if (H != -1 && S[i] == 'H' && i > (E[H] - 1)) H = -1;
	}

	for (int i = 0; i < G; i++) if (S[i] == 'H' && (E[i] - 1) >= G) res++;
	for (int i = 0; i < H; i++) if (S[i] == 'G' && (E[i] - 1) >= H) res++;

	if (G != -1 && H != -1) res++;
	cout << res << "\n";

	return 0;
}