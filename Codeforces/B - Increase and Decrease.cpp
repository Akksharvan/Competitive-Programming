#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "

int main() {
	int n;
	cin >> n;

	vector<int> n_array(n);
	for (int i = 0; i < n; i++) {
		cin >> n_array[i];
	}

	long long int sum = 0;
	for (const int& i : n_array) {
		sum += i;
	}

	if (sum % n == 0) {
		cout << n << nl;
	}
	else {
		cout << n - 1 << nl;
	}

	return 0;
}