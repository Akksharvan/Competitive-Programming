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
		long long int n, m;
		cin >> n >> m;

		int tn = n;
		int nt = 0;
		int nf = 0;
		int kz = 0;

		while (tn % 10 == 0) {
			nt++, nf++;
			tn /= 10;
		}

		while (tn % 2 == 0) {
			nt++;
			tn /= 2;
		}

		while (tn % 5 == 0) {
			nf++;
			tn /= 5;
		}

		long long int k = 1;

		while (nt < nf && (k * 2) <= m) {
			nt++;
			kz++;

			k *= 2;
		}

		while (nf < nt && (k * 5) <= m) {
			nf++;
			kz++;

			k *= 5;
		}

		while (k * 10 <= m) {
			kz++;
			k *= 10;
		}

		if (kz == 0) {
			cout << n * m << nl;
		}
		else {
			long long int f = m / k;
			cout << n * k * f << nl;
		}
	}

	return 0;
}