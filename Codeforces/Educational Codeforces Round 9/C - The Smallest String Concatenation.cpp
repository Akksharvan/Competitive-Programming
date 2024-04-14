#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<string> A(N); for (auto &i : A) cin >> i;

    auto F = [&] (const string &x, const string &y) { return (x + y) < (y + x); };
    sort(begin(A), end(A), F); string S = accumulate(begin(A), end(A), string(""));

    cout << S << "\n";
    return 0;
}