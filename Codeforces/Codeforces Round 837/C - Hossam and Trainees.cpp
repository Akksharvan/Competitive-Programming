#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

array<int, (int) 1e5 + 1> max_prime;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> primes;
	for (int i = 2; i <= (int) 1e5; i++) {
		if (!max_prime[i]) {
			primes.push_back(i);
			for (int j = i; j <= (int) 1e5; j += i) {
				max_prime[j] = i;
			}
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
		}

		map<int, int> divisor_count;
		for (int &x : a) {
			set<int> divisors;
			divisors.insert(x);

			for (const int &prime : primes) {
				if (x % prime == 0) {
					divisors.insert(prime);
				}

				while (x % prime == 0) {
					x /= prime;
					divisors.insert(x);
				}
			}

			for (const int &d : divisors) {
				divisor_count[d]++;
			}
		}

		bool s = false;
		for (const pair<int, int> &p : divisor_count) {
			if (p.first != 1 && p.second >= 2) {
				s = true;
			}
		}

		if (s) {
			cout << "YES" << nl;
		}
		else {
			cout << "NO" << nl;
		}
	}

	return 0;
}