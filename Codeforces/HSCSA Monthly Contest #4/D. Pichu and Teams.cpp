#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N; vector<pair<int, char>> P(N);
	for (pair<int, char> &p : P) cin >> p.second >> p.first;

	sort(begin(P), end(P));
	int res = 0; queue<pair<int, char>> Q1, Q2;

	for (pair<int, char> &p : P) {
		if (!(p.first % 2)) Q1.push(p);
		else Q2.push(p);
	}

	while (!Q1.empty() && !Q2.empty()) {
		pair<int, char> p1 = Q1.front(); Q1.pop();
		pair<int, char> p2 = Q2.front(); Q2.pop();
		if (p1.second == p2.second) res++;
	}

	cout << res << "\n";
	return 0;
}