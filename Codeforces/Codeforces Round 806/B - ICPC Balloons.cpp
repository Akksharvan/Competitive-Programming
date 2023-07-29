#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, b = 0;
		string s;
		cin >> n >> s;

		set<int> sp;
		for (char& c : s) {
			if (!sp.count(c)) {
				b += 2;
			}
			else {
				b += 1;
			}

			sp.insert(c);
		}

		cout << b << nl;
	}

	return 0;
}