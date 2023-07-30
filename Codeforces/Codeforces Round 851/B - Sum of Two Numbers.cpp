#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a;
	while (n) { a.push_back(n % 10); n /= 10; }
	reverse(begin(a), end(a));

	bool bit = 0;
	vector<int> x, y;

	for (int &i : a) {
		if (!(i % 2)) { x.push_back(i / 2); y.push_back(i / 2); }
		else if (bit) {
			x.push_back(i / 2); y.push_back((i / 2) + 1);
			bit = 0;
		}
		else {
			x.push_back((i / 2) + 1); y.push_back(i / 2);
			bit = 1;
		}
	}

	int X = 0, Y = 0;
	for (int i = 0; i < (int) a.size(); i++) {
		X *= 10, Y *= 10;
		X += x[i], Y += y[i];
	}

	cout << X << " " << Y << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}