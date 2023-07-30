#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	vector<int> A(N); for (int &i : A) cin >> i;

	int M; cin >> M;
	vector<int> B(M); for (int &i : B) cin >> i;

	int R = 0;
	for (int &b : B) for (int &a : A) if (!(b % a)) R = max(R, b / a);

	int G = 0;
	for (int &b : B) for (int &a : A) if (!(b % a) && (b / a) == R) G++;

	cout << G << "\n";
	return 0;
}