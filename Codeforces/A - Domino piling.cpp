#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N; cin >> M >> N; if (M > N) swap(M, N);
	int res = (N * (M / 2)) + (M % 2 ? N / 2 : 0);

	cout << res << "\n";
	return 0;
}