#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	vector<set<string>> A(N);

	for (set<string> &a : A) {
		string s; int K; cin >> s >> K;
		while (K--) { cin >> s; a.insert(s); }
	}

	int res = INT_MIN;
	for (set<string> &a : A) {
		for (set<string> &b : A) {
			int ret = 1; if (a == b) continue;
			for (const string &s : a) if (b.count(s)) ret++;
			res = max(res, ret);
		}
	}

	cout << res << "\n";
	return 0;
}