#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	sort(begin(s), end(s));

	set<string> d; do { d.insert(s); }
	while (next_permutation(begin(s), end(s)));

	cout << (int) d.size() << "\n";
	for (const string &w : d) cout << w << "\n";

	return 0;
}