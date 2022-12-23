#include <bits/stdc++.h>

using namespace std;

bool can_beat(vector<int> &die_one, vector<int> &die_two) {
	int case_win = 0;
	int case_loss = 0;

	for (const int &roll_one : die_one) {
		for (const int &roll_two : die_two) {
			if (roll_one > roll_two) {
				case_win++;
			} else if (roll_one < roll_two) {
				case_loss++;
			}
		}
	}

	if (case_win > case_loss) {
		return true;
	} else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	vector<vector<int>> C_possibilities;

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			for (int k = 1; k <= 10; k++) {
				for (int l = 1; l <= 10; l++) {
					C_possibilities.push_back({i, j, k, l});
				}
			}
		}
	}

	while (T--) {
		bool possible = false;

		vector<int> A(4), B(4);
		cin >> A[0] >> A[1] >> A[2] >> A[3] >> B[0] >> B[1] >> B[2] >> B[3];

		if (can_beat(A, B) || can_beat(B, A)) {
			if (can_beat(B, A)) {
				vector<int> temporary_storage = B;
				B = A;
				A = temporary_storage;
			}

			for (vector<int> C : C_possibilities) {
				if (can_beat(B, C) && can_beat(C, A)) {
					possible = true;
					break;
				}
			}
		}

		if (possible) {
			cout << "yes" << "\n";
		} else {
			cout << "no" << "\n";
		}
	}

	return 0;
}