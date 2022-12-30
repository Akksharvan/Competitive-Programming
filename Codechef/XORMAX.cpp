#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
	int T;
	cin >> T;
	
	while (T--) {
	    string A, B;
	    cin >> A >> B;
	    
	    int N = (sz(A) + sz(B)) / 2;
	    int a = 0, b = 0;
	    
	    for (char c : A) {
	        if (c == '1') {
	            a++;
	        }
	    }
	    
	    for (char c : B) {
	        if (c == '1') {
	            b++;
	        }
	    }
	    
	    int S = abs(N - b - a);
	    vector<int> ANS;
	    for (int i = 0; i < N; i++) {
	        if (S) {
	            ANS.push_back(0);
	            S--;
	        }
	        else {
	            ANS.push_back(1);
	        }
	    }
	    
	    sort(ANS.rbegin(), ANS.rend());
	    
	    for (int i = 0; i < N; i++) {
	        cout << ANS[i];
	    }
	    
	    cout << nl;
	    
	}
	return 0;
}
