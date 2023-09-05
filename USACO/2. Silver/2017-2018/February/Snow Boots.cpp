#include <bits/stdc++.h>
using namespace std;

int N; int B;
int R = INT_MAX;

array<int, 250> F, S, D;
array<array<bool, 250>, 250> V;

void foo (int i, int b) {
	if (V[i][b]) return;
	else V[i][b] = 1;

	if (i == N - 1) R = min(R, b);
	for (int j = i + 1; j < min(N, i + 1 + D[b]); j++) if (F[j] <= S[b]) foo(j, b);
	for (int c = b + 1; c < B; c++) if (F[i] <= S[c]) foo(i, c);
}

int main() {
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> B;
	for (int i = 0; i < N; i++) cin >> F[i];
	for (int i = 0; i < N; i++) cin >> S[i] >> D[i];

	foo(0, 0);
	cout << R << "\n";

	return 0;
}