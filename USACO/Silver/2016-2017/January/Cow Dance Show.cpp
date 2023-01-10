#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<int> C;

bool possible(int K) {
	int time = 0;
	priority_queue<int, vector<int>, greater<int>> stage;

	for (int i = 0; i < K; i++) stage.push(C[i]);
	for (int i = K; i < N; i++) stage.push(stage.top() + C[i]), stage.pop();
	while (!stage.empty()) time = max(time, stage.top()), stage.pop();
	

	if (time <= T) return true;
	else return false;
}

int main() {
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> T;
	for (int i = 0; i < N; i++) { int c; cin >> c; C.push_back(c); }

	int K = 1, R = N;
	while (K < R) {
		int M = K + (R - K) / 2;
		if (possible(M)) R = M;
		else K = M + 1;
	}

	cout << K << "\n";
	return 0;
}