#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n; int res = 0;
	map<int, int> f; int ret = 1;

	for (int i = 1; i < 13; i++) { ret *= 5; res += n / ret; }
	cout << res << "\n";
	
	return 0;
}