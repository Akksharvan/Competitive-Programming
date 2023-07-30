#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	vector<int> A(N); for (int &i : A) cin >> i;
	
	sort(begin(A), end(A)); deque<int> B; for (int &i : A) B.push_back(i);
	cout << ((N - 1) / 2) << "\n"; while (size(B) > 1) { cout << B.back() << " "; cout << B.front() << " "; B.pop_back(); B.pop_front(); }
	
	if (!B.empty()) cout << B.front();
	return 0;
}