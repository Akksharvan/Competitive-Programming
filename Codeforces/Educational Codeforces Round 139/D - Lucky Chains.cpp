#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

array<int, (int) 1e7 + 1> max_primes;
array<vector<int>, (int) 1e7 + 1> prime_multiples;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 2; i <= (int) 1e7; i++) {
		if (!max_primes[i]) {
			for (int j = i; j <= (int) 1e7; j += i) {
				max_primes[j] = i;
				prime_multiples[i].push_back(j);
			}
		}
	}

	int n;
	cin >> n;

	while (n--) {
		int x, y;
		cin >> x >> y;

		if (gcd(x, y) > 1) {
			cout << 0 << nl;
		}
		else if (gcd(x, y) == 1) {
			if (x % 2 == 1 && y % 2 == 1) {
				cout << 1 << nl;
			}
			else if (y - x == 1) {
				cout << -1 << nl;
			}
			else {
				int d = y - x;
				int k = (int) 1e7;

				vector<int> prime_divisors;
				while (d != 1) {
					int prime = max_primes[d];
					prime_divisors.push_back(prime);

					while (d % prime == 0) {
						d /= prime;
					}
				}

				for (const int &p : prime_divisors) {
					int m = *upper_bound(prime_multiples[p].begin(), prime_multiples[p].end(), x);
					k = min(k, m - x);
				}

				cout << k << nl;
			}
		}
	}

	return 0;
}