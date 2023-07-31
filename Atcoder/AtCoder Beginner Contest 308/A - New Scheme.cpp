#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int X = -1, Y;
	while (cin >> Y) {
		if (Y % 25) { cout << "No" << "\n"; return 0; }
		if (Y < X) { cout << "No" << "\n"; return 0; }
		if (Y < 100) { cout << "No" << "\n"; return 0; }
		if (Y > 675) { cout << "No" << "\n"; return 0; }

		X = Y;
	}

	cout << "Yes" << "\n";
	return 0;
}