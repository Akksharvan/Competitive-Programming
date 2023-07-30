#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    vector<pair<int, int>> B;
    vector<pair<int, int>> C;

    for (int i = 0; i < N; i++) {
        if (A[i] > 0) B.push_back({A[i], i + 1});
        if (A[i] < 0) C.push_back({A[i], i + 1});
    }

    sort(rbegin(B), rend(B));
    sort(begin(C), end(C));

    vector<pair<int, int>> R;

    if (size(C) == 0) { for (int i = 1; i < N; i++) R.push_back({i + 1, i}); }
    else if (size(B) == 0) { for (int i = N; i > 1; i--) R.push_back({i - 1, i}); }
    else if (size(C) <= 7) {
        while (A[B[0].second - 1] < 20) { A[B[0].second - 1] *= 2; R.push_back({B[0].second, B[0].second}); }
        for (pair<int, int> &i : C) R.push_back({i.second, B[0].second});
        for (int i = 1; i < N; i++) R.push_back({i + 1, i});
    }
    else if (size(B) <= 7) {
        while (A[C[0].second - 1] > -20) { A[C[0].second - 1] *= 2; R.push_back({C[0].second, C[0].second}); }
        for (pair<int, int> &i : B) R.push_back({i.second, C[0].second});
        for (int i = N; i > 1; i--) R.push_back({i - 1, i});
    }
    else {
        if (B[0].first >= abs(C[0].first)) {
            for (pair<int, int> &i : C) R.push_back({i.second, B[0].second});
            for (int i = 1; i < N; i++) R.push_back({i + 1, i});
        }
        else {
            for (pair<int, int> &i : B) R.push_back({i.second, C[0].second});
            for (int i = N; i > 1; i--) R.push_back({i - 1, i});
        }
    }
    
    cout << size(R) << "\n";
    for (pair<int, int> &i : R) cout << i.first << " " << i.second << "\n";
    
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}