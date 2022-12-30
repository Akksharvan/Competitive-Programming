#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int i_1 = 0;
		int i_2, s_1, s_2;

		for (int i = 0; i < sz(s); i++) {
			if (s[i] == '+') {
				s_1 = i;
				i_2 = i + 1;
				s_2 = sz(s) - (s_1 + 1);
			}
		}

		string sub_1 = s.substr(i_1, s_1);
		string sub_2 = s.substr(i_2, s_2);

		cout << stoi(sub_1, nullptr, 10) + stoi(sub_2, nullptr, 10) << nl;
	}

	return 0;
}