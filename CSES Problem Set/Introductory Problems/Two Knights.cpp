#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long int n; cin >> n;
	for (long long int i = 1; i <= n; i++) cout << (i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2)) << "\n";

	return 0;
}