#include <bits/stdc++.h>
using namespace std;

bool F (array<long long, 3> &x, array<long long, 3> &y) {
	long long A = x[1] * (y[1] + y[2]);
	long long B = y[1] * (x[1] + x[2]);
	
	if (A == B) return (x[0] < y[0]);
	else return A > B;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	vector<array<long long, 3>> A(N);

	for (int i = 1; i <= N; i++) {
		array<long long, 3> j; j[0] = i;
		cin >> j[1] >> j[2]; A[i - 1] = j;
	}

	sort(begin(A), end(A), F);
	for (array<long long, 3> &i : A) cout << i[0] << " ";

	cout << "\n";
	return 0;
}