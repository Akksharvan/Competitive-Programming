#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

vector<vector<int>> adjacent_cows(1e5);
vector<int> connected_cows(1e5);
vector<bool> visited(1e5);

int N, M, CC = 0;
string S;

void dfs (int node) {
	visited[node] = true;
	connected_cows[node] = CC;

	for (int next_node : adjacent_cows[node]) {
		if (!visited[next_node] && S[node] == S[next_node]) {
			dfs(next_node);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);

	cin >> N >> M >> S;

	for (int i = 0; i < N - 1; i++) {
		int X, Y;
		cin >> X >> Y;
		X--, Y--;

		adjacent_cows[X].push_back(Y);
		adjacent_cows[Y].push_back(X);
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			CC++;
			dfs(i);
		}
	}

	for (int i = 0; i < M; i++) {
		int A, B;
		char C;
		cin >> A >> B >> C;
		A--, B--;

		if (connected_cows[A] != connected_cows[B]) {
			cout << 1;
		}
		else if (S[A] == C) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}

	cout << nl;
	return 0;
}