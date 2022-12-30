#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n; string s;
    cin >> n >> s; 

    int ret = 0;
    for (int l = 1; l <= (int) (n / 2); l++) if (s.substr(0, l) == s.substr(l, l)) ret = l;
   
    cout << (ret ? (n - ret + 1) : n) << "\n";
	return 0;
}