#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int res = 1, ret = 1;
	for (int i = 1; i < (int) s.size(); i++) {
		if (s[i] == s[i - 1]) { ret++; res = max(res, ret); }
		else { res = max(res, ret); ret = 1; }
	}

	cout << res << "\n";
	return 0;
}