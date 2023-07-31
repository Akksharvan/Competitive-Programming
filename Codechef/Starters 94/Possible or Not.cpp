#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, B; cin >> N >> B;
    vector<int> A(N); for (int &a : A) cin >> a;

    vector<int> C; for (int &a : A) if ((a & B) == B) C.push_back(a);
    int R = INT_MAX; for (int &c : C) R &= c;

    if (R == B) cout << "YES" << "\n";
    else cout << "NO" << "\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}