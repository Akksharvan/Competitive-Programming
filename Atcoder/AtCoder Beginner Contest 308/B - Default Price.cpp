#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	
	vector<string> A(N);
	vector<string> B(M);
	vector<int> C(M + 1);
	
	for (string &i : A) cin >> i;
	for (string &i : B) cin >> i;
	for (int &i : C) cin >> i;

	map<string, int> D; D["N/A"] = C[0];
	for (int i = 0; i < M; i++)  D[B[i]] = C[i + 1];

	int R = 0;
	for (string &i : A) {
		if (D.count(i)) R += D[i];
		else R += D["N/A"];
	}

	cout << R << "\n";
	return 0;
}