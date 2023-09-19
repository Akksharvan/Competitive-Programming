#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	priority_queue<int> C;
	for (int i = 0; i < N; i++) { int w; cin >> w; C.push(w); }

	int res = 0;
	while (!C.empty()) { if (res <= C.top()) { res++; } C.pop(); }

	cout << res << "\n";
	return 0;
}