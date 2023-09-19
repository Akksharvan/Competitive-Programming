#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    sort(begin(A), end(A));

    if (count(begin(A), end(A), A[N - 1]) == N) {
        cout << -1 << "\n";
        return;
    }

    vector<int> B;
    vector<int> C;

    for (int &i : A) {
        if (i != A[N - 1]) B.push_back(i);
        else C.push_back(i);
    }

    cout << size(B) << " ";
    cout << size(C) << "\n";

    for (int &i : B) cout << i << " ";
    cout << "\n";

    for (int &i : C) cout << i << " ";
    cout << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}