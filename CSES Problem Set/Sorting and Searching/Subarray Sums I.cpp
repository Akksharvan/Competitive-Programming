#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;

	vector<int> arr(n + 1), psum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	int l = 0, r = 0, c = 0;
	while (l <= n) {
		while (r <= n) {
			if (psum[r] - psum[l] < x) {
				r++;
			}
			else {
				break;
			}
		}

		if (psum[r] - psum[l] == x) {
			c++;
		}

		l++;
	}

	cout << c << nl;
	return 0;
}