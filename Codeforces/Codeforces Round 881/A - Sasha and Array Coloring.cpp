#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    deque<int> B; int R = 0;
    sort(begin(A), end(A));

    for (int &i : A) B.push_back(i);
    while (size(B) > 1) {
        R += (B.back() - B.front());
        B.pop_front(); B.pop_back();
    }

    cout << R << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
	
	return 0;
}