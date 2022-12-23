#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		string a, b;
		cin >> a >> b;

		int a_size, b_size;
		int a_x_count = sz(a) - 1, b_x_count = sz(b) - 1;

		if (a[sz(a) - 1] == 'S') {
			a_size = 0;
		}
		else if (a[sz(a) - 1] == 'M') {
			a_size = 1;
		}
		else if (a[sz(a) - 1] == 'L') {
			a_size = 2;
		}

		if (b[sz(b) - 1] == 'S') {
			b_size = 0;
		}
		else if (b[sz(b) - 1] == 'M') {
			b_size = 1;
		}
		else if (b[sz(b) - 1] == 'L') {
			b_size = 2;
		}

		if (a_size != b_size) {
			if (a_size < b_size) {
				cout << "<" << nl;
			}
			else {
				cout << ">" << nl;
			}
		}
		else {
			if (a_size == 0) {
				if (a_x_count < b_x_count) {
				cout << ">" << nl;
				}
				else if (a_x_count > b_x_count) {
					cout << "<" << nl;
				}
				else {
					cout << "=" << nl;
				}
			}
			else if (a_size == 2) {
				if (a_x_count < b_x_count) {
				cout << "<" << nl;
				}
				else if (a_x_count > b_x_count) {
					cout << ">" << nl;
				}
				else {
					cout << "=" << nl;
				}
			}
			else {
				cout << "=" << nl;
			}
		}
	}

	return 0;
}