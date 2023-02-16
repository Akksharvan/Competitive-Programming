#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	if (n == 1) cout << 1 << "\n";
	else if (n <= 3) cout << "NO SOLUTION" << "\n";
	else if (n == 4) cout << "2 4 1 3" << "\n";
	else {
		for (int i = 0; i < n; i += 2) cout << i + 1 << " ";
		for (int i = 1; i < n; i += 2) cout << i + 1 << " ";
	}

	cout << "\n";
	return 0;
}