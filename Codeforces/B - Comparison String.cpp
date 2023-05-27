#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; string S; cin >> N >> S;
    int ret = 1, ans = 1;
    
    for (int i = 0; i < N; i++) {
        if (S[i] == S[i + 1]) ret++;
        else {
            ans = max(ans, ret);
            ret = 1;
        }
    }
    
    ans = max(ans, ret);
    cout << ans + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}