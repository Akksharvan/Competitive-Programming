#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

bool ALICE (int k, multiset<int>& integers) {
	for (int i = 1; i <= k; i++) {
		int val = k - i + 1;

		if (integers.empty()) {
			return false;
		}
		else if (val < *integers.begin()) {
			return false;
		}
		else if (val > *prev(integers.end())) {
			integers.erase(prev(integers.end()));
		}
		else {
			integers.erase(prev(integers.upper_bound(val)));
		}

		if (!integers.empty()) {
			int new_val = *integers.begin() + val;
			integers.insert(new_val);
			integers.erase(integers.begin());
		}
	}

	return true;
}

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
			int a;
			cin >> a;
			integers.insert(a);
		}

		int k = n;
		multiset<int> integers_copy = integers;

		while (!ALICE(k, integers_copy)) {
			integers_copy = integers;
			k--;
		}

		cout << k << nl;
	}

	return 0;
}