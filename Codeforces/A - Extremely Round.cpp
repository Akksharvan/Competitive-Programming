#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

bool extremely_round (int x) {
	int zero_counter = 0, digits = 0;

	while (x > 0) {
		if (x % 10 == 0) {
			x /= 10;
			zero_counter++;
			digits++;
		}
		else {
			x /= 10;
			digits++;
		}
	}

	if (zero_counter + 1 == digits) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> er((int) 1e6);
	vector<int> per((int) 1e6);

	for (int i = 1; i < (int) 1e6; i++) {
		er[i] = extremely_round(i);
	}

	for (int i = 1; i < (int) 1e6; i++) {
		per[i] = per[i - 1] + er[i];
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << per[n] << nl;
	}

	return 0;
}