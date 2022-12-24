#include <bits/stdc++.h>
using namespace std;

bool consistent (vector<string> &inputs, vector<int> &outputs) {
	vector<bool> bits((int) inputs[0].size());
	vector<bool> ignore((int) inputs.size());

	for (int i = 0; i < (int) inputs.size(); i++) {
		for (int j = 0; j < (int) inputs[i].size(); j++) {
			if (!ignore[i]) {
				bool if_found = true;

				for (int k = 0; k < (int) inputs.size(); k++) {
					if (!ignore[k]) {
						if (inputs[i][j] == inputs[k][j] && outputs[i] != outputs[k]) {
							if_found = false;
							break;
						}
					}
				}

				if (if_found) {
					for (int k = 0; k < (int) inputs.size(); k++) {
						if (!ignore[k] && inputs[k][j] == inputs[i][j]) ignore[k] = 1;
					}

					i = 0; j = -1;
				}
			}
		}
	}

	for (const bool &ign : ignore) {
		if (!ign) return false;
	}
	
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		vector<string> inputs(M);
		vector<int> outputs(M);

		for (int i = 0; i < M; i++) cin >> inputs[i] >> outputs[i];
		bool ok = consistent(inputs, outputs);

		if (ok) cout << "OK" << "\n";
		else cout << "LIE" << "\n";
	}

	return 0;
}