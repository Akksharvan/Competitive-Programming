#include <bits/stdc++.h>

using namespace std;

#define nl "\n"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		int a_time = abs(1 - a);
		int b_time = abs(b - c) + abs(1 - c);

		if (a_time < b_time) {
			cout << "1" << nl;
		} else if (a_time > b_time) {
			cout << "2" << nl;
		} else {
			cout << "3" << nl;
		}
	}

	return 0;
}