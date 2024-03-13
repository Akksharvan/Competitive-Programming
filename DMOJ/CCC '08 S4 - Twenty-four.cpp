#include <bits/stdc++.h>
using namespace std;

int F (vector<int> A) {
    if (size(A) == 1) return (A.back() <= 24 ? A.back() : 0);
    sort(begin(A), end(A)); int R = 0;

    do {
        vector<int> C, B = A;

        int X = B.back(); B.pop_back();
        int Y = B.back(); B.pop_back();
        
        C = B; C.push_back(X + Y); R = max((F(C) <= 24 ? F(C) : 0), R); C.pop_back();
        C = B; C.push_back(X - Y); R = max((F(C) <= 24 ? F(C) : 0), R); C.pop_back();
        C = B; C.push_back(X * Y); R = max((F(C) <= 24 ? F(C) : 0), R); C.pop_back();

        if (Y && !(X % Y)) { C = B; C.push_back(X / Y); R = max((F(C) <= 24 ? F(C) : 0), R); }
    }
    while (next_permutation(begin(A), end(A)));

    return R;
}

void solve () {
    vector<int> A(4); for (auto &i : A) cin >> i;
    sort(begin(A), end(A)); int R = F(A);

    cout << R << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}