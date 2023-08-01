#include <bits/stdc++.h>
using namespace std;

int F (vector<int> &A) {
    int X = *max_element(begin(A), end(A));
    for (int i = 0; i < (int) size(A); i++) if (A[i] == X) return i;
}

int G (vector<int> &A) {
    int X = *min_element(begin(A), end(A));
    for (int i = 0; i < (int) size(A); i++) if (A[i] == X) return i;
}

bool H (vector<int> &A) {
    return (count(begin(A), end(A), A[0]) == (int) size(A));
}

void K (vector<pair<int, int>> &A) {
    for (pair<int, int> &i : A) cout << i.first << " " << i.second << "\n";
}

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    if (H(A)) { cout << 0 << "\n"; return; }
    if (A[G(A)] == 1) { cout << -1 << "\n"; return; }

    vector<pair<int, int>> R;
    while (!H(A)) {
        int i = F(A), j = G(A);
        A[i] = ceil((double) A[i] / A[j]);
        R.push_back({(i + 1), (j + 1)});
    }

    cout << size(R) << "\n";
    K(R); return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}