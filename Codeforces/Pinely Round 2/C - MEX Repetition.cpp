#include <bits/stdc++.h>
using namespace std;

int B (vector<int> &A) {
    vector<bool> C(size(A) + 1);
    for (int &i : A) C[i] = 1;

    for (int i = 0; i < size(C); i++) {
        if (C[i]) continue;
        else return i;
    }
}

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N); for (int &i : A) cin >> i;

    A.push_back(B(A)); K %= (N + 1);
    stack<int> C; stack<int> D;

    for (int i = 0; i <= N; i++) {
        if (i < K) { C.push(A[size(A) - 1]); A.pop_back(); }
        else { D.push(A[size(A) - 1]); A.pop_back(); }
    }

    for (int i = 0; i < N; i++) {
        if (!C.empty()) { cout << C.top() << " "; C.pop(); }
        else { cout << D.top() << " "; D.pop(); }
    }

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