#include <bits/stdc++.h>
using namespace std;

bool G (int N, int i, int j, int k, int l) { return ((i + k < 0) || (i + k > (N - 1)) || (j + l < 0) || (j + l > (N - 1))); }
bool F (vector<vector<char>> &A, int N, int k, int l) { for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if ((A[i][j] == '#') && G(N, i, j, k, l)) return 0; return 1; }

vector<vector<char>> H (vector<vector<char>> &A, int N, int k, int l) {
	vector<vector<char>> B(N, vector<char> (N, '.'));
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (A[i][j] == '#') B[i + k][j + l] = '#';

	return B;
}

bool M (vector<vector<char>> &A, vector<vector<char>> &B, int N) { for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (A[i][j] == '#' && A[i][j] == B[i][j]) return 0; return 1; }
vector<vector<char>> L (vector<vector<char>> &A, vector<vector<char>> &B, int N) {
	vector<vector<char>> C(N, vector<char> (N, '.'));
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (A[i][j] == '#' || B[i][j] == '#') C[i][j] = '#';

	return C;
}

int main() {
	freopen("bcs.in", "r", stdin);
	freopen("bcs.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

	int N, K; cin >> N >> K; vector<vector<char>> A(N, vector<char> (N));
	for (vector<char> &i : A) for (char &j : i) cin >> j;

	vector<pair<vector<vector<char>>, int>> B;
	for (int i = 1; i <= K; i++) {
		vector<vector<char>> C(N, vector<char> (N));
		for (vector<char> &j : C) for (char &k : j) cin >> k;

		for (int j = -(N - 1); j < N; j++) {
			for (int k = -(N - 1); k < N; k++) {
				if (!F(C, N, j, k)) continue;
				vector<vector<char>> D = H(C, N, j, k); B.push_back({D, i});
			}
		}
	}

	for (int i = 0; i < size(B); i++) {
		for (int j = i + 1; j < size(B); j++) {
			if (B[i].second == B[j].second || !M(B[i].first, B[j].first, N) || L(B[i].first, B[j].first, N) != A) continue;
			cout << B[i].second << " " << B[j].second << "\n"; return 0;
		}
	}

	return 0;
}