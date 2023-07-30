#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
 
	int N; cin >> N;
	vector<int> A(N); for (int &i : A) cin >> i;
 
	vector<int> DP;
	for (int i = 0; i < N; i++) {
		if (lower_bound(begin(DP), end(DP), A[i]) == end(DP)) DP.push_back(A[i]);
		else *lower_bound(begin(DP), end(DP), A[i]) = A[i];
	}
 
	cout << size(DP) << "\n";
	return 0;
}