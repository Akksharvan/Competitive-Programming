#include <bits/stdc++.h>

using namespace std;
#define nl "\n"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	map<int, char> conversion_table;
	for (int i = 1; i <= 26; i++) {
		conversion_table[i] = ('a' + (i - 1));
	}

	while (q--) {
		int N;
		string C;
		cin >> N >> C;

		stack<char> decoded_word;
		
		for (int i = N - 1; i >= 0; i--) {
			int code;

			if (C[i] == '0') {
				i -= 2;
				code = (int) (10 * (C[i] - '0')) + (int) (C[i + 1] - '0');
			}
			else {
				code = (C[i] - '0');
			}

			decoded_word.push(conversion_table[code]);
		}

		while (!decoded_word.empty()) {
			cout << decoded_word.top();
			decoded_word.pop();
		}

		cout << nl;
	}

	return 0;
}