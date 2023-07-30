#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<vector<int>> A(N + 1);
	vector<vector<int>> B(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		A[a].push_back(b);
		B[b].push_back(a);
	}

	vector<int> V(N + 1);
	vector<vector<int>> C;

	for (int i = 1; i <= N; i++) {
		if (V[i]) continue;
		
		stack<int> S;
		vector<int> E;
		S.push(i);

		while (!S.empty()) {
			int n = S.top(); S.pop();
			if (V[n]) continue;

			V[n] = 1; E.push_back(n);
			for (int l : A[n]) if (!V[l]) S.push(l);
			for (int l : B[n]) if (!V[l]) S.push(l);
		}

		C.push_back(E);
	}
	
	int R = 0; vector<int> D(N + 1);
	for (int i = 1; i <= N; i++) D[i] = size(B[i]);

	for (vector<int> &c : C) {
		queue<int> Q; vector<int> O;
		for (int i : c) if (D[i] == 0) Q.push(i);

		while (!Q.empty()) {
			int n = Q.front(); Q.pop();
			O.push_back(n);

			for (int l : A[n]) {
				D[l]--;
				if (D[l] == 0) Q.push(l);
			}
		}

		if (size(O) < size(c)) R += size(c);
		else R += (size(c) - 1);
	}

	cout << R << "\n";
	return 0;
}