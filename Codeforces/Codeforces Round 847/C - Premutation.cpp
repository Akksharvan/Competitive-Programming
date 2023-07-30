#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int> (n - 1));
	for (vector<int> &vi : arr) for (int &i : vi) cin >> i;

	map<int, int> f;
	for (vector<int> &vi : arr) f[vi[0]]++;
	int val = ((begin(f) -> second > prev(end(f)) -> second) ? begin(f) -> first : prev(end(f)) -> first);
	
	vector<int> ans;
	for (vector<int> &vi : arr) if (vi[0] != val) ans = vi;

	cout << val << " ";
	for (int &i : ans) cout << i << " ";
	
	cout << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}