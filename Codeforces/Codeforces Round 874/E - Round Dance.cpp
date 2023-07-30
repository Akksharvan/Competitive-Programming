#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<set<int>> A(N + 1);

	for (int i = 1; i <= N; i++) {
		int n; cin >> n;
		A[i].insert(n);
		A[n].insert(i);
	}

	int B = 0, CC = 0;
	
	stack<int> C;
	vector<int> V(N + 1);

	for (int i = 1; i <= N; i++) {
		if (V[i]) continue;
		bool D = 0; CC++; C.push(i);

		while (!C.empty()) {
			int n = C.top(); C.pop();
			if (V[n]) continue;
			else V[n] = 1;

			if ((int) A[n].size() < 2) D = 1;
			for (int l : A[n]) if (!V[l]) C.push(l);
		}

		B += D;
	}

	cout << CC - max(0, B - 1) << " " << CC << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}