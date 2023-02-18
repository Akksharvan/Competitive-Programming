#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int &i : a) cin >> i;

	sort(begin(a), end(a));
	multiset<int> res;

	for (int &i : a) {
		res.insert(i);
		if (res.find(i - 1) != end(res)) res.erase(res.find(i - 1));
	}

	cout << ((int) res.size()) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}