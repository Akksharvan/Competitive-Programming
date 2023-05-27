#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N; int CC = 0;
	vector<vector<int>> A(N + 1);
	vector<vector<int>> B(N + 1);
	vector<vector<int>> C(N + 1);

	for (int i = 1; i <= N; i++) {
		int j; cin >> j;

		A[i].push_back(j);
		A[j].push_back(i);

		B[i].push_back(j);
		C[j].push_back(i);
	}

	vector<vector<int>> D;
	vector<bool> V(N + 1);

	for (int i = 1; i <= N; i++) {
		if (!V[i]) {
			vector<int> d; stack<int> e; e.push(i);
			while (!e.empty()) {
				int n = e.top(); e.pop(); d.push_back(n); V[n] = 1;
				for (int &a : A[n]) if (!V[a]) e.push(a);
			}

			D.push_back(d); CC++;
		}
	}

	vector<pair<int, int>> R;
	vector<pair<int, int>> F(CC);
	
	for (int i = 0; i < CC; i++) {
		vector<int> r; for (int j : D[i]) if (C[j].empty()) r.push_back(j);
		if (r.empty()) { F[i] = {D[i][0], D[i][0]}; continue; }

		int a = B[r[0]][0], b = B[B[r[0]][0]][0];
		while (a != b) { a = B[a][0]; b = B[B[b][0]][0]; }

		if ((int) r.size() > 1) {
			for (int j = 1; j < (int) r.size(); j++) { 
				R.push_back({a, r[j]});
			}
		}

		F[i] = {a, r[0]};
	}

	if (CC == 1 && F[0].first == F[0].second) { cout << 0 << "\n"; return 0; }
	for (int i = 0; i < CC; i++) R.push_back({F[i].first, F[(i + 1) % CC].second});

	cout << (int) R.size() << "\n";
	for (pair<int, int> &r : R) cout << r.first << " " << r.second << "\n";

	return 0;
}