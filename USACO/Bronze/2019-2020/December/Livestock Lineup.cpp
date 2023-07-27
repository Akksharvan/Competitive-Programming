#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

	const array<string, 8> C = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

	int N; cin >> N;
	map<string, vector<string>> A;

	for (int i = 0; i < N; i++) {
		string a, b, c;
		cin >> a >> c >> c >> c >> c >> b;

		A[a].push_back(b);
		A[b].push_back(a);
	}

	map<string, bool> V; int B = 0;
	vector<string> D; for (string c : C) V[c] = 0;

	while (B < 8) {
		for (string c : C) {
			if (V[c]) continue;
			if (size(A[c]) >= 2) continue;

			stack<string> E; E.push(c);
			while (!E.empty()) {
				string S = E.top(); E.pop();
				V[S] = 1; B++; D.push_back(S);

				for (string s : A[S]) {
					if (V[s]) continue;
					E.push(s);
				}
			}
		}
	}

	for (string d : D) cout << d << "\n";
    return 0;
}