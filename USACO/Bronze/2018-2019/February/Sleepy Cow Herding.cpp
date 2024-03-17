#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    
	ios::sync_with_stdio(0);
    cin.tie(0);

    int X, Y, Z;
    cin >> X >> Y >> Z;
    
    if (X > Y) swap(X, Y);
    if (X > Z) swap(X, Z);
    if (Y > Z) swap(Y, Z);

    if (X + 2 == Z) cout << 0 << "\n";
    else if (X + 2 == Y || Y + 2 == Z) cout << 1 << "\n";
    else cout << 2 << "\n";
    
    cout << max(Y - X, Z - Y) - 1 << "\n";

    return 0;
}
