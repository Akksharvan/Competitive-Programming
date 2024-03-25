#include <bits/stdc++.h>
using namespace std;

int F (int i, int A1, int A2, int B1, int B2) {
    if (A1 <= i && i <= A2) i = A2 - (i - A1);
    if (B1 <= i && i <= B2) i = B2 - (i - B1);

    return i;
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    int A1, A2, B1, B2; cin >> A1 >> A2 >> B1 >> B2;

    vector<int> R(N + 1);
    for (int i = 1; i <= N; i++) {
        int X = 1, Y = F(i, A1, A2, B1, B2);
        while (i != Y) Y = F(Y, A1, A2, B1, B2), X++;

        int Z = K % X;
        while (Z) Y = F(Y, A1, A2, B1, B2), Z--;

        R[Y] = i;
    }

    for (int i = 1; i <= N; i++) cout << R[i] << "\n";
    return 0;
}