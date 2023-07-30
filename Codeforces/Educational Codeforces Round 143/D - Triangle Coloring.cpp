#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long F (long long A, long long B, long long M) {
    A %= M; long long R = 1;

    while (B > 0) {
        if (B & 1) R = R * A % M;
        A = A * A % M; B >>= 1;
    }

    return R;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long N; cin >> N; N /= 3;
	vector<array<long long, 3>> A(N);

	long long R = 1;
	for (array<long long, 3> &i : A) {
		cin >> i[0] >> i[1] >> i[2];
		sort(begin(i), end(i));

		if (i[0] == i[1] && i[1] == i[2]) { R *= 3; R %= MOD; }
		else if (i[0] == i[1]) { R *= 2; R %= MOD; }
	}

	long long B = 1; long long C = 1;
	for (long long i = (N / 2) + 1; i <= N; i++) B *= i, B %= MOD;
	for (long long i = 2; i <= N / 2; i++) C *= i, C %= MOD;

	C = F(C, MOD - 2, MOD);
	cout << ((((B * C) % MOD) * R) % MOD) << "\n";

	return 0;
}