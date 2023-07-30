#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	array<int, (int) 1e6 + 1> DP{};
	fill(begin(DP), end(DP), INT_MAX - 1); DP[0] = 0;
 
	for (int i = 1; i <= (int) 1e6; i++) {
		int n = i; DP[i] = min(DP[i], DP[i - (i % 10)] + 1);
		while (n) { n /= 10; DP[i] = min(DP[i], DP[i - (n % 10)] + 1); }
	}
 
	int N; cin >> N;
	cout << DP[N] << "\n";
 
    return 0;
}