#include <bits/stdc++.h>
using namespace std;

set<int> R;

void F4(vector<int> &A, vector<int> &B, int C) {
	for (int i = 0; i < size(B); i++) {
		R.insert(C + B[i]);
	}
}

void F3(vector<int> &A, vector<int> &B, int C) {
	for (int i = 0; i < size(A); i++) {
		vector<int> NA = A; NA.erase(begin(NA) + i);
		vector<int> NB = B; NB.push_back(A[i]);
		F4(NA, NB, C - A[i]);
	}
}

void F2(vector<int> &A, vector<int> &B, int C) {
	for (int i = 0; i < size(B); i++) {
		vector<int> NA = A; NA.push_back(B[i]);
		vector<int> NB = B; NB.erase(begin(NB) + i);
		F3(NA, NB, C + B[i]);
	}
}

void F1(vector<int> &A, vector<int> &B, int C) {
	for (int i = 0; i < size(A); i++) {
		vector<int> NA = A; NA.erase(begin(NA) + i);
		vector<int> NB = B; NB.push_back(A[i]);
		F2(NA, NB, C - A[i]);
	}
}

int main() {
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

	vector<int> A(10), B(10);
	for (int &a : A) cin >> a;
	for (int &b : B) cin >> b;

	F1(A, B, 1000);
	cout << size(R) << "\n";

	return 0;
}