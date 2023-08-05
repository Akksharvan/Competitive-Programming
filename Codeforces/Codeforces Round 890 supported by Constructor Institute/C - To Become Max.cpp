#include <bits/stdc++.h>
using namespace std;

bool G (int I, int M, int K, vector<int> &A) {
    long long R = 0; vector<int> D = A;
    for (int i = I; i < size(D) - 1; i++) {
        if (A[i] >= (M - (i - I))) {
            if (R <= K) return 1;
            else return 0;
        }

        R += (M - (i - I) - A[i]);
        D[i] = (M - (i - I));
    }

    if (D[size(D) - 1] < D[size(D) - 2] - 1) return 0;
    else if (R > K) return 0;

    return 1;
}

int F (int I, int K, vector<int> &A) {
    int L = A[I] - 1;
    int H = A[I] + K;

    while (L < H) {
        int M = L + (H - L + 1) / 2;
        if (G(I, M, K, A)) L = M;
        else H = M - 1;
    }
 
    return L;
}

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N); for (int &i : A) cin >> i;

    int R = *max_element(begin(A), end(A));
    for (int i = 0; i < N - 1; i++) R = max(R, F(i, K, A));



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