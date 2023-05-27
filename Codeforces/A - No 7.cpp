#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string x; cin >> x; x = to_string(stoi(x) - 1);
	while (stoi(x)) {
		bool g = 1; for (char &c : x) if (c == '7') g = 0;
		if (g) { cout << x << "\n"; return 0; }
		else { x = to_string(stoi(x) - 1); }
	}

	return 0;
}