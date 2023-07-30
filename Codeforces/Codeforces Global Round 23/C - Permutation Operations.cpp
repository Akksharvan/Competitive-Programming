#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N; cin >> N;
  vector<int> A(N); for (int &i : A) cin >> i;

  vector<pair<int, int>> B;
  for (int i = 1; i < N; i++) {
    if (A[i] > A[i - 1]) continue;
    else B.push_back({A[i - 1] - A[i], i});
  }

  sort(rbegin(B), rend(B));
  vector<int> C(N, 1);

  for (int i = 0; i < size(B); i++) {
    C[N - 1 - i] = B[i].second + 1;
  }

  for (int &i : C) cout << i << " ";
  cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}