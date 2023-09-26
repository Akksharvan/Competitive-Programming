#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S; cin >> S;
    vector<int> A, B; 

    for (int i = 0; i < size(S); i++) if (S[i] == 'B') A.push_back(i + 1);
    A.push_back(0); A.push_back(size(S) + 1); sort(begin(A), end(A));


    for (int i = 0; i < size(A) - 1; i++) B.push_back(A[i + 1] - A[i] - 1);
    if (size(B) == 1) { cout << 0 << "\n"; return; }

    sort(begin(B), end(B));
    cout << accumulate(begin(B), end(B), 0LL) - B[0] << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}