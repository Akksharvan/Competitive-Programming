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
		int n;
		cin >> n;

		multiset<int> integers;
		for (int i = 0; i < n; i++) {
			int integer;
			cin >> integer;
			integers.insert(integer);
		}

		long long int beauty = *prev(integers.end()) + *prev(prev(integers.end())) - (*integers.begin() + *next(integers.begin()));
		cout << beauty << nl;
	}

	return 0;
}