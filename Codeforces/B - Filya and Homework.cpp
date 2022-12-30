#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main() {
	int n;
	cin >> n;

	set<int> arr;
	while (n--) {
		int i;
		cin >> i;
		arr.insert(i);
	}

	if (arr.size() <= 2) {
		cout << "YES" << nl;
	}
	else if (arr.size() == 3) {
		cerr << "here" << nl;
		if (*next(arr.begin()) - *arr.begin() == *next(next(arr.begin())) - *next(arr.begin())) {
			cout << "YES" << nl;
		}
		else {
			cout << "NO" << nl;
		}
	}
	else {
		cout << "NO" << nl;
	}

	return 0;
}
