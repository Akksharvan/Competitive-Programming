#include <bits/stdc++.h>
using namespace std;

const string pi = "3141592653589793238462643383279";

void solve() {
	string n;
	cin >> n;

	int res = 0;
	while (res < (int) n.size()) {
		if (n[res] != pi[res]) break;
		else res++;
	}

	cout << res << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}