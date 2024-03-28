#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    vector<int> A(N); for (auto &i : A) cin >> i;

    set<pair<int, int>> B;
    for (int i = 0; i < N; i++) B.insert({A[i], i});

    while (!B.empty()) {
        pair<int, int> i = *prev(end(B));
        B.erase(prev(end(B)));

        if (i.second > 0 && abs(A[i.second - 1] - A[i.second]) > K) {
            B.erase(B.find({A[i.second - 1], i.second - 1}));
            A[i.second - 1] = A[i.second] - K; B.insert({A[i.second - 1], i.second - 1});
        }

        if (i.second < N - 1 && abs(A[i.second + 1] - A[i.second]) > K) {
            B.erase(B.find({A[i.second + 1], i.second + 1}));
            A[i.second + 1] = A[i.second] - K; B.insert({A[i.second + 1], i.second + 1});
        }
    }

    for (auto &i : A) cout << i << " ";
    cout << "\n"; return 0;
}