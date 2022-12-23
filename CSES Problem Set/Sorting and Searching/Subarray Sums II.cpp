#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	long long int c = 0;
	cin >> n >> x;

	vector<long long int> arr(n + 1), psum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	map<long long int, int> psum_counter;
	for (int r = 0; r <= n; r++) {
		c += psum_counter[psum[r] - x];
		psum_counter[psum[r]]++;
	}

	cout << c << nl;
	return 0;
}