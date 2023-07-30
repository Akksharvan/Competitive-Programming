#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S; cin >> S;
	string D; cin >> D;

	array<int, 2> A{};
	for (char &c : D) {
		if (c == 'B') A[0]++;
		if (c == 'K') A[0]--;
		if (c == 'P') A[1]++;
		if (c == 'T') A[1]--;
	}

	if (A[0] < 0) A[0] = ((abs(A[0]) % 26) * -1);
	else A[0] = (A[0] % 26);

	if (A[1] < 0) A[1] = ((abs(A[1]) % size(S)) * -1);
	else A[1] = (A[1] % size(S));

	for (char &c : S) {
		if (A[0] < 0) {
			for (int i = 0; i < abs(A[0]); i++) {
				if (c == 'a') c = 'z';
				else c -= 1;
			}
		}

		if (A[0] > 0) {
			for (int i = 0; i < abs(A[0]); i++) {
				if (c == 'z') c = 'a';
				else c += 1;
			}
		}
	}

	if (A[1] > 0) {
		for (int i = size(S) - abs(A[1]); i < size(S); i++) cout << S[i];
		for (int i = 0; i < size(S) - abs(A[1]); i++) cout << S[i];
		cout << "\n";
	}

	if (A[1] < 0) {
		for (int i = abs(A[1]); i < size(S); i++) cout << S[i];
		for (int i = 0; i < abs(A[1]); i++) cout << S[i];
		cout << "\n";
	}

	if (A[1] == 0) cout << S << "\n";
	return 0;
}