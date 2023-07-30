#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for (int &i : A) cin >> i;

	vector<int> B(10);
	for (int &i : A) B[i]++;

	cout << "- 0 \n";
	cout.flush();

	for (int &i : A) cin >> i;
	vector<int> C(10); for (int &i : A) C[i]++;

	int T = -1;
	for (int i = 1; i <= 9; i++) {
		if (C[i] > B[i]) T = i;
	}

	if (T == -1) {
		cout << "- 0 \n";
		cout.flush(); C = vector<int>(10);

		for (int &i : A) cin >> i;
		for (int &i : A) C[i]++;

		for (int i = 1; i <= 9; i++) {
			if (C[i] > B[i]) T = i;
		}
	}

	vector<int> D;
	for (int i = 0; i < N; i++) {
		if (A[i] != T) D.push_back(i + 1);
	}

	N -= size(D);
    A.resize(N);

	cout << '-' << " " << size(D) << " ";
	for (int &i : D) cout << i << " ";
	
	cout << "\n";
	cout.flush();

	for (int &i : A) cin >> i;
	for (int i = 0; i < N; i++) {
		if (A[i] != T) {
			cout << '!' << " " << (i + 1) << "\n";
			cout.flush(); return;
		}
	}

	cout << '-' << " " << 0 << "\n";
	cout.flush();

	for (int &i : A) cin >> i;
	for (int i = 0; i < N; i++) {
		if (A[i] != T) {
			cout << '!' << " " << (i + 1) << "\n";
			cout.flush(); return;
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}