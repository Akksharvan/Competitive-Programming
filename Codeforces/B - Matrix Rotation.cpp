#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

void rotate(array<array<int, 2>, 2> &matrix) {
	swap(matrix[0][0], matrix[0][1]);
	swap(matrix[0][0], matrix[1][1]);
	swap(matrix[0][0], matrix[1][0]);
}

bool is_beautiful(array<array<int, 2>, 2> &matrix) {
	if (matrix[0][0] < matrix[0][1] && matrix[1][0] < matrix[1][1] && matrix[0][0] < matrix[1][0] && matrix[0][1] < matrix[1][1]) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		array<array<int, 2>, 2> matrix;
		cin >> matrix[0][0] >> matrix[0][1] >> matrix[1][0] >> matrix[1][1];

		bool beautiful = false;
		for (int i = 0; i < 4; i++) {
			rotate(matrix);
			beautiful = is_beautiful(matrix);
			if (beautiful) break;
		}

		if (beautiful) cout << "YES" << nl;
		else cout << "NO" << nl;
	}
	
	return 0;
}