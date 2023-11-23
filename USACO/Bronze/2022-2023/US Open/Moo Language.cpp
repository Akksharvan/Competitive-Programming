#include <bits/stdc++.h>
using namespace std;

bool F (vector<string> &x, vector<string> &y) { return size(x) < size(y); }

void solve () {
	int N, C, P; cin >> N >> C >> P;
	vector<vector<string>> A(4), B;

	for (int i = 0; i < N; i++) {
		string S, T; cin >> S >> T;

		if (T == "noun") A[0].push_back(S + " ");
		if (T == "conjunction") A[1].push_back(S + " ");

		if (T == "transitive-verb") A[2].push_back(S + " ");
		if (T == "intransitive-verb") A[3].push_back(S + " ");
	}

	// cerr << "Nouns : " << size(A[0]) << "\n";
	// for (string &i : A[0]) cerr << i << "\n";

	// cerr << "\n";

	// cerr << "Conjunctions : " << size(A[1]) << "\n";
	// for (string &i : A[1]) cerr << i << "\n";

	// cerr << "\n";

	// cerr << "Transitive Verbs : " << size(A[2]) << "\n";
	// for (string &i : A[2]) cerr << i << "\n";

	// cerr << "\n";

	// cerr << "Intransitive Verbs : " << size(A[3]) << "\n";
	// for (string &i : A[3]) cerr << i << "\n";

	// cerr << "\n";

	while (!A[3].empty()) {
		if (A[0].empty()) break; vector<string> S;

		S.push_back(A[0].back()); A[0].pop_back();
		S.push_back(A[3].back()); A[3].pop_back();

		B.push_back(S);
	}
	
	while (!A[2].empty()) {
		if (size(A[0]) < 2) break; vector<string> S;

		S.push_back(A[0].back()); A[0].pop_back();
		S.push_back(A[2].back()); A[2].pop_back();
		S.push_back(A[0].back()); A[0].pop_back();

		B.push_back(S);
	}

	if (B.empty()) { cout << 0 << "\n" << "\n"; return; }
	
	int M = P - min(P, (int) size(A[1])) + 2 * min(P, (int) size(A[1])); sort(rbegin(B), rend(B), F); string R1; int R2 = 0;
	while (size(B) > M) { vector<string> S = B.back(); B.pop_back(); for (int i = 0; i < size(S); i += 2) A[0].push_back(S[i]); }

	for (int i = size(B) - 1; i >= 0; i--) {
		if (size(B[i]) == 3 || A[0].empty() || A[2].empty()) break;

		B[i].push_back(A[0].back()); B[i][1] = A[2].back();
		A[0].pop_back(); A[2].pop_back(); 
	}

	sort(rbegin(B), rend(B), F);

	if (size(B[0]) == 3) {
		while (!A[0].empty() && C) {
			B[0].back() = B[0].back().substr(0, size(B[0].back()) - 1);
			B[0].push_back(", " + A[0].back()); A[0].pop_back(); C--;
		}
	}

	while (!A[1].empty()) {
		if (size(B) < 2) break; if (size(R1) != 0) R1 += " ";

		vector<string> S1 = B.back(); B.pop_back();
		vector<string> S2 = B.back(); B.pop_back();

		for (string &S : S1) R1 += S; R1 += A[1].back(); A[1].pop_back();
		for (string &S : S2) R1 += S; R1 = R1.substr(0, size(R1) - 1) + "."; R2 += size(S1) + size(S2) + 1;
	}

	while (!B.empty()) {
		if (size(R1) != 0) R1 += " "; vector<string> S1 = B.back(); B.pop_back();
		for (string &S : S1) R1 += S; R1 = R1.substr(0, size(R1) - 1) + "."; R2 += size(S1);
	}

	cout << R2 << "\n" << R1 << "\n";
	return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}