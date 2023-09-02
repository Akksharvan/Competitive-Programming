#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S; cin >> S;
    priority_queue<int> P;

    int R = 0, N = 0;

    for (char &c : S) {
        if (c == '+') N++;
        else if (c == '-') {
            N--; R = min(R, N);
            while (!P.empty() && N < P.top()) P.pop();
        }
        else if (c == '1') {
            if (!P.empty()) { cout << "NO" << "\n"; return; }
            else R = N;
        }
        else if (c == '0') {
            if (N < 2 || R == N) { cout << "NO" << "\n"; return; }
            else P.push(N);
        }
    }

    cout << "YES" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}