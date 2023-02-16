#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	map<char, int> m; for (char &c : s) m[c]++;

	int ret = 0; for (const pair<char, int> &p : m) ret += p.second % 2;
	if ((ret == 0) || (ret == 1 && (int) s.size() % 2)) {
		vector<char> a, b; char d = '0';
		for (const pair<char, int> &p : m) {
			if (p.second % 2) d = p.first;
			for (int i = 0; i < p.second / 2; i++) {
				a.push_back(p.first);
				b.push_back(p.first);
			}
		}

		for (char &c : a) cout << c;
		if (d != '0') cout << d; reverse(begin(b), end(b));

		for (char &c : b) cout << c;
		cout << "\n";
	}
	else cout << "NO SOLUTION" << "\n";

	return 0;
}