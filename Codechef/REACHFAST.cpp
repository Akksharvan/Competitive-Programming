#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int X, Y, K;
        cin >> X >> Y >> K;
        
        int D = abs(X - Y);
        if (D % K == 0) {
            cout << (int) (D / K) << endl;
        }
        else {
            cout << (int) (D / K) + 1 << endl;
        }
    }
	return 0;
}
