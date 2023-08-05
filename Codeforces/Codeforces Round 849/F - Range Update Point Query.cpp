#include <bits/stdc++.h>
using namespace std;

int F (int X) {
    int R = 0; while (X) { R += (X % 10); X /= 10; }
    return R;
}

void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N); for (int &i : A) cin >> i;
    set<int> B; for (int i = 0; i < N; i++) B.insert(i);

    while (Q--) {
        int T; cin >> T;
        if (T == 1) {
            int L, R; cin >> L >> R; L -= 2; R--;
            set<int>::iterator I = B.upper_bound(L);

            while (I != end(B) && *I <= R) {
                A[*I] = F(A[*I]); L = *I;
                if (A[*I] <= 9) B.erase(I);
                I = B.upper_bound(L);
            }
        }
        else {
            int X; cin >> X;
            cout << A[X - 1] << "\n";
        }
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