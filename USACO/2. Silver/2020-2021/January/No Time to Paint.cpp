#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	string F;
	cin >> N >> Q >> F;

	const char A = 'A';
	vector<int> fence(N + 1), fence_prefix(N + 1), fence_suffix(N + 1);
	for (int i = 0; i < N; i++) {
		fence[i + 1] = F[i] - A;
	}

	stack<int> active_colors;
	for (int i = 1; i <= N; i++) {
		fence_prefix[i] = fence_prefix[i - 1];

		while (!active_colors.empty() && active_colors.top() > fence[i]) {
			active_colors.pop();
		}

		if (active_colors.empty() || active_colors.top() < fence[i]) {
			active_colors.push(fence[i]);
			fence_prefix[i]++;
		}
	}

	reverse(fence.begin(), fence.end());

	while (!active_colors.empty()) {
		active_colors.pop();
	}

	for (int i = 1; i <= N; i++) {
		fence_suffix[i] = fence_suffix[i - 1];

		while (!active_colors.empty() && active_colors.top() > fence[i]) {
			active_colors.pop();
		}

		if (active_colors.empty() || active_colors.top() < fence[i]) {
			active_colors.push(fence[i]);
			fence_suffix[i]++;
		}
	}

	for (int i = 0; i < sz(fence_prefix); i++) {
		cerr << fence_prefix[i] << nl;
	}

	cerr << nl;

	for (int i = 0; i < sz(fence_suffix); i++) {
		cerr << fence_suffix[i] << nl;
	}

	for (int q = 0; q < Q; q++) {
		int a, b;
		cin >> a >> b;

		int strokes = fence_prefix[a - 1] + fence_suffix[N - b];
		cout << strokes << nl;
	}

	return 0;
}