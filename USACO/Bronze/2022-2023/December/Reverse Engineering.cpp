#include <bits/stdc++.h>
using namespace std;

bool foo (vector<string> &I, vector<int> &O) {
	vector<bool> B((int) I[0].size());
	vector<bool> IGN((int) I.size());

	for (int i = 0; i < (int) I.size(); i++) {
		for (int j = 0; j < (int) I[i].size(); j++) {
			if (!IGN[i]) {
				bool G = 1;

				for (int k = 0; k < (int) I.size(); k++) {
					if (!IGN[k]) {
						if (I[i][j] == I[k][j] && O[i] != O[k]) {
							G = false;
							break;
						}
					}
				}

				if (G) {
					for (int k = 0; k < (int) I.size(); k++) {
						if (!IGN[k] && I[k][j] == I[i][j]) IGN[k] = 1;
					}

					i = 0; j = -1;
				}
			}
		}
	}

	for (const bool &ign : IGN) if (!ign) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		vector<string> I(M);
		vector<int> O(M);

		for (int i = 0; i < M; i++) cin >> I[i] >> O[i];
		bool ok = foo(I, O);

		if (ok) cout << "OK" << "\n";
		else cout << "LIE" << "\n";
	}

	return 0;
}