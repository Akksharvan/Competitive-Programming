#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

array<int, (int) 1e3 + 1> max_primes;
vector<int> primes;

array<int, (int) 1e6 + 1> d;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 2; i <= (int) 1e3; i++) {
		if (!max_primes[i]) {
			primes.push_back(i);
			for (int j = i; j <= (int) 1e3; j += i) {
				max_primes[j] = i;
			}
		}
	}

	int n;
	cin >> n;

	vector<int> x(n);
	for (int &xi : x) {
		cin >> xi;
	}

	map<int, int> divisor_count;
	for (int &xi : x) {
		set<int> divisors;
		divisors.insert(xi);

		for (const int &prime : primes) {
			if (xi % prime == 0) {
				divisors.insert(prime);
			}

			while (xi % prime == 0) {
				xi /= prime;
				divisors.insert(xi);
			}
		}

		for (const int &d : divisors) {
			divisor_count[d]++;
		}
	}

	int max_divisor = 1;
	for (const pair<int, int> &p : divisor_count) {
		if (p.second >= 2) {
			max_divisor = max(max_divisor, p.first);
		}
	}

	cout << max_divisor << nl;
	return 0;
}