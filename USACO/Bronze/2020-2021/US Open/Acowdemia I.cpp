#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

array<int, (int) 1e5> P;
bool NP(int N, int H, int L) {
	if (P[N - H] < H) {
		if (P[N - H] == H - 1) {
			if ((N - H + L) >= N) {
				return false;
			}
			else if (P[N - H + L] >= H) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(P.begin(), P.begin() + N);

	int H = N;
	while (NP(N, H, L)) {
		H--;
	}

	cout << H << nl;
	return 0;
}