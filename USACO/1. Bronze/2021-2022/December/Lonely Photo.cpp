#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	long long int LP = 0;
	string S;
	cin >> N >> S;

	vector<char> C(N);
	for (int i = 0; i < N; i++) {
		C[i] = S[i];
	}

	vector<int> GC(N + 1), HC(N + 1);
	for (int i = 1; i <= N; i++) {
		GC[i] = GC[i - 1] + (C[i - 1] == 'G');
		HC[i] = HC[i - 1] + (C[i - 1] == 'H');
	}

	int L = 0, M = 0, R = 2;
	while (L <= N - 3) {
		while (R < N && (GC[R + 1] - GC[L] <= 1 || HC[R + 1] - HC[L] <= 1)) {
			R++;
		}
		
		while (M < R && (GC[M + 1] - GC[L] == 0 || HC[M + 1] - HC[L] == 0)) {
			M++;
		}
		
		LP += max(0, R - (L + 2)) - max(0, M - (L + 2));
		L++;
	}

	cout << LP << nl;
	return 0;
}