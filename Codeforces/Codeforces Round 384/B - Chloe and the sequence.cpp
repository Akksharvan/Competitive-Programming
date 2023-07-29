#include <bits/stdc++.h>
using namespace std;

array<long long int, 51> a;
array<long long int, 51> b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    for (int i = 1; i <= 50; i++) {
        a[i] = (1LL << (i - 1));
        b[i] = (1LL << (i));
    }

    long long int n, k;
    cin >> n >> k;

    for (long long int i = n; i >= 1; i--) {
        if (((k % b[i]) - a[i]) == 0) cout << i << "\n";
    }
    
	return 0;
}