#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N; string S; cin >> N >> S;
    vector<int> R1, R2;
    
    for (int i = 0; i < N; i++) {
        if (S[i] == '1' && (i & 1)) R1.push_back(i);
        else if (S[i] == '1' && !(i & 1)) R2.push_back(i);
    }

    int X = size(R1);
    int Y = size(R2);

    if (!(X & 1) && !(Y & 1)) cout << "YES" << "\n";
    else if ((X & 1) && !(Y & 1)) cout << "NO" << "\n";
    else if (!(X & 1) && (Y & 1)) cout << "NO" << "\n";
    else if ((X & 1) && (Y & 1)) {
        if (abs(R1.front() - R2.front()) > 1) cout << "YES" << "\n";
        else if (abs(R1.front() - R2.back()) > 1) cout << "YES" << "\n";
        else if (abs(R1.back() - R2.front()) > 1) cout << "YES" << "\n";
        else if (abs(R1.back() - R2.back()) > 1) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}