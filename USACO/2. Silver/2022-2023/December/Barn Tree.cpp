#include <bits/stdc++.h>
using namespace std;

vector<long long int> haybales((int) 2e5);
vector<long long int> subtree_sums((int) 2e5);
vector<long long int> subtree_sizes((int) 2e5);

vector<vector<int>> adj((int) 2e5);

vector<vector<long long int>> initial_sequence;
vector<vector<long long int>> final_sequence;

void subtree_sum (int node, int parent) {
	subtree_sums[node] = haybales[node];
	for (int &branch : adj[node]) if (branch != parent) subtree_sum(branch, node);
	for (int &branch : adj[node]) if (branch != parent) subtree_sums[node] += subtree_sums[branch];
}

void subtree_size (int node, int parent) {
	subtree_sizes[node] = 1;
	for (int &branch : adj[node]) if (branch != parent) subtree_size(branch, node);
	for (int &branch : adj[node]) if (branch != parent) subtree_sizes[node] += subtree_sizes[branch];
}

void calculate (int node, int parent, int layer) {
	for (int &branch : adj[node]) {
		if (branch != parent) {
			long long int haybales_needed = (subtree_sizes[branch] * (subtree_sums[0] / subtree_sizes[0])) - (subtree_sums[branch]);
			if (haybales_needed < 0) initial_sequence.push_back({layer, branch + 1, node + 1, abs(haybales_needed)});
			if (haybales_needed > 0) final_sequence.push_back({layer, node + 1, branch + 1, abs(haybales_needed)});
		}
	}

	for (int &branch : adj[node]) if (branch != parent) calculate(branch, node, layer + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> haybales[i];
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		a--, b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	subtree_sum(0, -1);
	subtree_size(0, -1);
	
	calculate(0, -1, 0);

	sort(initial_sequence.rbegin(), initial_sequence.rend());
	sort(final_sequence.begin(), final_sequence.end());

	cout << ((int) initial_sequence.size() + (int) final_sequence.size()) << "\n";
	for (vector<long long int> &seq : initial_sequence) cout << seq[1] << " " << seq[2] << " " << seq[3] << "\n";
	for (vector<long long int> &seq : final_sequence) cout << seq[1] << " " << seq[2] << " " << seq[3] << "\n";

	return 0;
}