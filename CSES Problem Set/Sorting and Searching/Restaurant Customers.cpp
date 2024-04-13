#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R = 0; cin >> N; vector<pair<int, int>> A(N);
    for (auto &[i, j] : A) cin >> i >> j;

    sort(begin(A), end(A));
    priority_queue<int, vector<int>, greater<int>> B;

    for (auto &i : A) {
        while (!B.empty() && B.top() < i.first) B.pop();
        B.push(i.second); R = max(R, ((int) size(B)));
    }

    cout << R << "\n";
    return 0;
}