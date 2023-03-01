#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> foo (string S) {
	vector<pair<int, int>> V; int x = 0, y = 0;
	
	for (int i = 0; i < (int) S.size(); i++) {
		if (i == 0 && S[i] != S[(int) S.size() - 1]) V.push_back({x, y});
		else if (i != 0 && S[i] != S[i - 1]) V.push_back({x, y});

		if (S[i] == 'E') x++;
		else if (S[i] == 'N') y++;
		else if (S[i] == 'W') x--;
		else if (S[i] == 'S') y--;
	}

	return V;
}

int SL (vector<pair<int, int>>& V) {
	int ret1 = 0, ret2 = 0;

	for (int i = 0; i < (int) V.size(); i++) {
		if (i != (int) V.size() - 1) ret1 += (V[i].first * V[i + 1].second);
		else ret1 += (V[i].first * V[0].second);
	}

	for (int i = 0; i < (int) V.size(); i++) {
		if (i != (int) V.size() - 1) ret2 += (V[i].second * V[i + 1].first);
		else ret2 += (V[i].second * V[0].first);
	}

	return (ret1 - ret2) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		string S; cin >> S;
		vector<pair<int, int>> V = foo(S); int ret = SL(V);

		if (ret > 0) cout << "CCW" << "\n";
		else cout << "CW" << "\n";
	}

	return 0;
}