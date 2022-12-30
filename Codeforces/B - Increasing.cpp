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

		vector<int> arr;
		bool good = true;

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			arr.push_back(a);
		}

		sort(arr.begin(), arr.end());
		for (int i = 1; i < n; i++) {
			if (arr[i] == arr[i - 1]) {
				good = false;
				break;
			}
		}

		if (good) {
			cout << "YES" << nl;
		}
		else {
			cout << "NO" << nl;
		}
	}

	return 0;
}