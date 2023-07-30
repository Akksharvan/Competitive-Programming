#include <bits/stdc++.h>
using namespace std;
 
vector<pair<int, int>> R;
 
void foo (int N, int A, int B, int C) {
    if (N == 1) { R.emplace_back(A, C); return; }
    else {foo(N - 1, A, C, B); R.emplace_back(A, C); foo(N - 1, B, A, C); return; }
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
    int N; cin >> N;
    foo(N, 1, 2, 3);
 
    cout << size(R) << "\n";
    for (pair<int, int> &r : R) cout << r.first << " " << r.second << "\n";
 
    return 0;
}