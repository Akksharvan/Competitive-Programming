#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> d(N, vector<int> (N));
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			cin >> d[i][j];
		}
	}

	vector<int> a(N);
	for (int i = 1; i < N; i++) {
		a[i] = a[i - 1] + d[i - 1][i];

		for (int j = 0; j < i; j++) {
			int min_val = *min_element(a.begin() + j, a.begin() + i + 1);
			int max_val = *max_element(a.begin() + j, a.begin() + i + 1);

			if (max_val - min_val != d[j][i]) {
				a[i] = a[i - 1] - d[i - 1][i];
				break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (i + 1 < N) cout << a[i] << " ";
		else cout << a[i] << "\n";
	}

	return 0;
}