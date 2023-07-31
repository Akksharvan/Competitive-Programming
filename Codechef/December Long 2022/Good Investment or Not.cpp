#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    int X, Y;
	    cin >> X >> Y;
	    
	    if (X >= (2 *Y)) {
	        cout << "YES" << endl;
	    }
	    else {
	        cout << "NO" << endl;
	    }
	}
	return 0;
}