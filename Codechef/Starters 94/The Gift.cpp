#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int X, N, M; cin >> X >> N >> M;
    cout << (X + M >= N ? "YES" : "NO");
    
    return 0;
}