#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> C(N);
	for (int &c : C) cin >> c;
	for (int &c : C) c--;

	vector<int> P(N);
	for (int &c : C) P[c]++;

	queue<int> Q;
	for (int i = 0; i < N; i++) if (!P[i]) Q.push(i);

	while (!Q.empty()) {
		if (P[C[Q.front()]] == 1) Q.push(C[Q.front()]);
		P[C[Q.front()]]--; Q.pop();
	}

	int res = 0;
	for (int &p : P) if (p) res++;

	cout << res << "\n";
	return 0;
}